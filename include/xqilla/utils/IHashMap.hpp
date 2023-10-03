/*
 * Copyright (c) 2010,
 *     John Snelson. All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef IHASHMAP_HPP
#define IHASHMAP_HPP

#include <string.h>

#include <xqilla/utils/HashMap.hpp>
#include <xqilla/framework/ReferenceCounted.hpp>

template<class KEY, class VALUE, class HASH = DefaultHashFunctor<KEY>, class EQUALS = DefaultEqualsFunctor<KEY> >
class IHashMap
{
private:
  struct Bucket
  {
    inline Bucket() : key(), value(), hash(0), death(0), next(0) {}
    inline Bucket(const Bucket *o, Bucket *n)
      : key(o->key), value(o->value), hash(o->hash), death(0), next(n) {}

    inline void *operator new(size_t, Bucket *p) { return (void*)p; }

    inline bool isDead(const Bucket *age) const
    {
      return death != 0 && age > death;
    }

    KEY key;
    VALUE value;
    size_t hash;
    const Bucket *death; // Age when this entry was deleted
    Bucket *next;
  };

public:
  class iterator
  {
  public:
    inline iterator() : bkt_(0), age_(0) {}

    inline iterator(Bucket *s, const Bucket *a)
      : bkt_(s), age_(a)
    {
      while(bkt_ < age_ && bkt_->isDead(age_)) {
        ++bkt_;
      }
    }

    inline iterator &operator++()
    {
      if(bkt_ < age_) {
        do {
          ++bkt_;
        } while(bkt_ < age_ && bkt_->isDead(age_));
      }

      return *this;
    }

    inline iterator operator++(int)
    {
      iterator tmp = *this;
      ++*this;
      return tmp;
    }

    inline bool operator==(const iterator &o) const
    {
      return bkt_ == o.bkt_;
    }

    inline bool operator!=(const iterator &o) const
    {
      return bkt_ != o.bkt_;
    }

    inline const KEY &getKey() const
    {
      return bkt_->key;
    }

    inline VALUE &getValue() const
    {
      return bkt_->value;
    }

  private:
    Bucket *bkt_;
    const Bucket *age_;
  };

public:
  inline IHashMap(size_t initialCapacity, const HASH &hash = HASH(), const EQUALS &equals = EQUALS())
    : hash_(hash),
      equals_(equals),
      segment_(0),
      age_(0),
      dead_(0)
  {
    Segment::create(initialCapacity, segment_, age_);
  }

  inline void put(const KEY &key, const VALUE &value)
  {
    put(key, hash_(key), value);
  }
  inline void put(const KEY &key, size_t hash, const VALUE &value)
  {
    doInsert(key, hash, &value);
  }

  inline void remove(const KEY &key)
  {
    return remove(key, hash_(key));
  }
  inline void remove(const KEY &key, size_t hash)
  {
    doInsert(key, hash, 0);
  }

  inline const VALUE *get(const KEY &key) const
  {
    return get(key, hash_(key));
  }
  inline const VALUE *get(const KEY &key, size_t hash) const
  {
    return segment_->get(key, hash, equals_, age_);
  }

  inline bool contains(const KEY &key) const
  {
    return contains(key, hash_(key));
  }
  inline bool contains(const KEY &key, size_t hash) const
  {
    return segment_->get(key, hash, equals_, age_) != 0;
  }

  inline iterator begin()
  {
    return iterator(segment_->getBuckets(), age_);
  }
  inline iterator end()
  {
    return iterator((Bucket*)age_, age_);
  }

  inline size_t size() const { return segment_->getCount(age_) - dead_; }
  inline size_t capacity() const { return segment_->getCapacity(); }
  inline size_t isEmpty() const { return segment_->getCount(age_) == dead_; }

  inline size_t getHash(const KEY &key) const
  {
    return hash_(key);
  }

private:
  class Segment : public ReferenceCounted
  {
  public:
    typedef RefCountPointer<Segment> Ptr;

    static inline void create(size_t capacity, Segment::Ptr &result, const Bucket *&resultAge)
    {
      size_t tableSize = calculateTableSize(capacity);
      void *mem = malloc(sizeof(Segment) + sizeof(Bucket*) * tableSize +
                         sizeof(Bucket) * capacity);
      new ((Segment*)mem) Segment(tableSize, capacity);
      result = (Segment*)mem;
      resultAge = ((Segment*)mem)->getAge();
    }
    static inline void copy(size_t capacity, const Segment::Ptr &prev, const Bucket *prevAge,
                            Segment::Ptr &result, const Bucket *&resultAge)
    {
      size_t tableSize = calculateTableSize(capacity);
      void *mem = malloc(sizeof(Segment) + sizeof(Bucket*) * tableSize +
                         sizeof(Bucket) * capacity);
      new ((Segment*)mem) Segment(tableSize, capacity, prev, prevAge);
      result = (Segment*)mem;
      resultAge = ((Segment*)mem)->getAge();
    }
    virtual void decrementRefCount() const
    {
      if(--const_cast<unsigned int&>(_ref_count) == 0) {
        Bucket *bkt = getBuckets();
        for(size_t i = 0; i < capacity_; ++i) {
          bkt[i].~Bucket();
        }
        free((void*)this);
      }
    }

    inline const Bucket *put(const KEY &key, size_t hash, const VALUE *value,
                             const EQUALS &equals, const Bucket *age, size_t &dead)
    {
      if(count_ >= capacity_) return 0;

      // Compare age to see if we can update in-place
      Bucket *nw = &getBuckets()[count_];
      if(nw > age) return 0;

      // Check if the entry already exists
      Bucket **tableEntry = &table_[hash & (tableSize_ - 1)];
      Bucket *bkt = find(*tableEntry, key, hash, equals, age);
      if(bkt != 0 && !bkt->isDead(age)) {
        // Give the existing entry its death age
        bkt->death = nw;
        ++dead;
      } else if(value == 0) return age;

      // Allocate a new bucket
      ++count_;

      if(value == 0) {
        // This is a delete, but we consume a new bucket anyway,
        // so that we increase the age
        nw->death = nw;
        ++dead;
      } else {
        nw->key = key;
        nw->hash = hash;
        nw->value = *value;

        // Link it to the hash table
        nw->next = *tableEntry;
        *tableEntry = nw;
      }

      return nw + 1;
    }
    inline const VALUE *get(const KEY &key, size_t hash,
                            const EQUALS &equals, const Bucket *age) const
    {
      Bucket *bkt = find(table_[hash & (tableSize_ - 1)], key, hash, equals, age);
      return (bkt == 0 || bkt->isDead(age)) ? 0 : &bkt->value;
    }

    inline size_t getCapacity() const { return capacity_; }
    inline size_t getCount(const Bucket *age) const { return age - getBuckets(); }
    inline const Bucket *getAge() const { return &getBuckets()[count_]; }
    inline Bucket *getBuckets() const { return (Bucket*)(table_ + tableSize_); }

  private:
    Segment(size_t tableSize, size_t capacity)
      : tableSize_(tableSize),
        capacity_(capacity),
        count_(0)
    {
      assert(tableSize_ != 0);
      memset(table_, 0, tableSize_ * sizeof(Bucket*));

      Bucket *bkt = getBuckets();
      for(size_t i = 0; i < capacity_; ++i) {
        new (bkt + i) Bucket();
      }
    }
    Segment(size_t tableSize, size_t capacity, const Segment::Ptr &prev, const Bucket *prevAge)
      : tableSize_(tableSize),
        capacity_(capacity),
        count_(0)
    {
      assert(tableSize_ != 0);
      memset(table_, 0, tableSize_ * sizeof(Bucket*));

      Bucket *bkt = getBuckets();
      Bucket *pbkt = prev->getBuckets();
      for(; pbkt < prevAge; ++pbkt) {
        if(!pbkt->isDead(prevAge)) {
          // Allocate a new bucket
          Bucket *nw = bkt + count_;
          ++count_;

          // Link it to the hash table
          Bucket **tableEntry = &table_[pbkt->hash & (tableSize_ - 1)];
          new (nw) Bucket(pbkt, *tableEntry);
          *tableEntry = nw;
        }
      }

      for(size_t i = count_; i < capacity_; ++i) {
        new (bkt + i) Bucket();
      }
    }

    void *operator new(size_t, Segment *p) { return (void*)p; }

    static inline size_t calculateTableSize(size_t capacity)
    {
      // Hash table should be at least 4 thirds capacity
      size_t tableSize = capacity - 1;

      // Find the next highest power of two
      tableSize |= tableSize >> 1;
      tableSize |= tableSize >> 2;
      tableSize |= tableSize >> 4;
      tableSize |= tableSize >> 8;
      tableSize |= tableSize >> 16;
      tableSize |= tableSize >> 32;
      ++tableSize;
      return tableSize;
    }

    inline Bucket *find(Bucket *bkt, const KEY &key, size_t hash,
                        const EQUALS &equals, const Bucket *age) const
    {
      while(bkt >= age) {
        bkt = bkt->next;
      }
      while(bkt != 0) {
        if(hash == bkt->hash && equals(key, bkt->key))
          return bkt;
        bkt = bkt->next;
      }

      return 0;
    }

    size_t tableSize_;
    size_t capacity_;
    size_t count_;

    Bucket *table_[];
  };

  inline void doInsert(const KEY &key, size_t hash, const VALUE *value)
  {
    size_t dead = dead_;
    const Bucket *newAge /*hippy*/ = segment_->put(key, hash, value, equals_, age_, dead);
    if(newAge == 0) {
      RefCountPointer<Segment> newSegment;
      Segment::copy(size() * 2, segment_, age_, newSegment, newAge);
      dead = 0;
      newAge = newSegment->put(key, hash, value, equals_, newAge, dead);
      segment_.swap(newSegment);
    }
    age_ = newAge;
    dead_ = dead;
  }

  HASH hash_;
  EQUALS equals_;

  RefCountPointer<Segment> segment_;
  const Bucket *age_;
  size_t dead_;
};

#endif
