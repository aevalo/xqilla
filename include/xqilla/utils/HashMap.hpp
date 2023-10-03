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

#ifndef HASHMAP_HPP
#define HASHMAP_HPP

#include <ostream>
#include <assert.h>

#include <xqilla/framework/XQillaExport.hpp>
#include <xqilla/framework/BasicMemoryManager.hpp>
#include <xqilla/utils/XPath2Utils.hpp>
#include <xqilla/utils/lookup3.hpp>

#include <xercesc/util/XMemory.hpp>
#include <xercesc/framework/MemoryManager.hpp>

template<class T>
struct DefaultEqualsFunctor
{
  inline bool operator()(const T &a, const T &b) const
  {
    return a == b;
  }
};

template<>
struct DefaultEqualsFunctor<const XMLCh*>
{
  inline bool operator()(const XMLCh *a, const XMLCh *b) const
  {
    return XPath2Utils::equals(a, b);
  };
};

template<class T>
struct DefaultHashFunctor
{
  inline size_t operator()(const T &a) const
  {
    return a.hash();
  }
};

template<>
struct DefaultHashFunctor<const XMLCh*>
{
  inline size_t operator()(const XMLCh *a) const
  {
    if(a == 0) return 0;
    uint32_t pc = 0xF00BAA56, pb = 0xBADFACE2;
    hashlittle2((void*)a, XPath2Utils::uintStrlen(a) * sizeof(XMLCh), &pc, &pb);
    return pc + (((size_t)pb)<<32);
  }
};

template<>
struct DefaultHashFunctor<int>
{
  inline size_t operator()(int a) const
  {
    uint32_t pc = 0xF00BAA56, pb = 0xBADFACE2;
    hashword2((uint32_t*)&a, sizeof(int) / sizeof(uint32_t), &pc, &pb);
    return pc + (((size_t)pb)<<32);
  }
};

template<typename TYPE>
struct DefaultHashFunctor<TYPE*>
{
  inline size_t operator()(TYPE *a) const
  {
    uint32_t pc = 0xF00BAA56, pb = 0xBADFACE2;
    hashword2((uint32_t*)&a, sizeof(TYPE*) / sizeof(uint32_t), &pc, &pb);
    return pc + (((size_t)pb)<<32);
  }
};

template<class KEY, class VALUE, class HASH = DefaultHashFunctor<KEY>, class EQUALS = DefaultEqualsFunctor<KEY>, int UNALLOCATED_SIZE = 13>
class HashMap : public XERCES_CPP_NAMESPACE_QUALIFIER XMemory
{
private:
  struct Bucket
  {
    Bucket() : key(), value(), state(EMPTY), hash(0), next(0) {}

    inline void *operator new(size_t, Bucket *p) { return (void*)p; }

    inline void set(KEY k, VALUE v, size_t h)
    {
      key = k;
      value = v;
      hash = h;
      state = OCCUPIED;
    }

    inline void setToDelete()
    {
      key = KEY();
      value = VALUE();
      state = DELETED;
    }

    KEY key;
    VALUE value;
    enum State { EMPTY, OCCUPIED, DELETED } state;
    size_t hash;
    Bucket *next;
  };

public:
  class iterator
  {
  public:
    inline iterator()
      : ptr_(0), end_(0), map_(0)
    {
    }

    inline iterator(Bucket *s, Bucket *e, HashMap *m = 0)
      : ptr_(s), end_(e), map_(m)
    {
      while(ptr_ != end_ && ptr_->state != Bucket::OCCUPIED) {
        ++ptr_;
      }
    }

    inline iterator &operator++()
    {
      if(map_) {
        ptr_ = map_->findNextDuplicate(ptr_);
      }
      else if(ptr_ != end_) {
        do {
          ++ptr_;
        } while(ptr_ != end_ && ptr_->state != Bucket::OCCUPIED);
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
      return ptr_ == o.ptr_;
    }

    inline bool operator!=(const iterator &o) const
    {
      return ptr_ != o.ptr_;
    }

    inline const KEY &getKey() const
    {
      return ptr_->key;
    }

    inline VALUE &getValue() const
    {
      return ptr_->value;
    }

  private:
    Bucket *ptr_, *end_;
    HashMap *map_; ///< Set if this is a duplicates iterator

    friend class HashMap;
  };

private:
  static inline size_t nextLowerPowerOfTwo(size_t i)
  {
    // Find the next highest or equal power of two
    --i;
    i |= i >> 1;
    i |= i >> 2;
    i |= i >> 4;
    i |= i >> 8;
    i |= i >> 16;
    i |= i >> 32;
    ++i;
    // Next lower power of two
    return i >> 1;
  }

  static inline size_t calculateAttic(size_t size)
  {
    assert(size);
    return size > 1 ? nextLowerPowerOfTwo(size) : 1;
  }

  static inline size_t nextCapacity(size_t capacity)
  {
    size_t attic = calculateAttic(capacity);
    return ((attic << 1) * 114) / 100;
  }

  inline Bucket *createBuckets(size_t size) const
  {
    return size <= UNALLOCATED_SIZE ? (Bucket*)inlineBuckets_ :
      (Bucket*)mm_->allocate(sizeof(Bucket) * size);
  }

  static inline size_t bucketsSize(size_t size)
  {
    return size <= UNALLOCATED_SIZE ? UNALLOCATED_SIZE : size;
  }

public:
  HashMap(bool resizable,
          XERCES_CPP_NAMESPACE_QUALIFIER MemoryManager *mm = BasicMemoryManager::get(),
          const HASH &hash = HASH(), const EQUALS &equals = EQUALS())
    : mm_(mm),
      buckets_((Bucket*)inlineBuckets_),
      capacity_(UNALLOCATED_SIZE),
      attic_(calculateAttic(capacity_)),
      lastKnownEmpty_(buckets_ + capacity_),
      count_(0),
      deleted_(0),
      resizable_(resizable),
      hash_(hash),
      equals_(equals)
  {
    for(size_t i = 0; i < capacity_; ++i) {
      new (buckets_ + i) Bucket();
    }
  }

  HashMap(size_t initialCapacity, bool resizable,
          XERCES_CPP_NAMESPACE_QUALIFIER MemoryManager *mm = BasicMemoryManager::get(),
          const HASH &hash = HASH(), const EQUALS &equals = EQUALS())
    : mm_(mm),
      buckets_(createBuckets(initialCapacity)),
      capacity_(bucketsSize(initialCapacity)),
      attic_(calculateAttic(capacity_)),
      lastKnownEmpty_(buckets_ + capacity_),
      count_(0),
      deleted_(0),
      resizable_(resizable),
      hash_(hash),
      equals_(equals)
  {
    for(size_t i = 0; i < capacity_; ++i) {
      new (buckets_ + i) Bucket();
    }
  }

  HashMap(const HashMap &o)
    : mm_(o.mm_),
      buckets_(createBuckets(o.capacity_)),
      capacity_(bucketsSize(o.capacity_)),
      attic_(calculateAttic(capacity_)),
      lastKnownEmpty_(buckets_ + capacity_),
      count_(0),
      deleted_(0),
      resizable_(o.resizable_),
      hash_(o.hash_),
      equals_(o.equals_)
  {
    for(size_t i = 0; i < capacity_; ++i) {
      new (buckets_ + i) Bucket();
    }
    insert(o.buckets_, o.buckets_ + o.capacity_, /*overwrite*/false);
  }

  HashMap(const HashMap &o, XERCES_CPP_NAMESPACE_QUALIFIER MemoryManager *mm)
    : mm_(mm),
      buckets_(createBuckets(o.capacity_)),
      capacity_(bucketsSize(o.capacity_)),
      attic_(calculateAttic(capacity_)),
      lastKnownEmpty_(buckets_ + capacity_),
      count_(0),
      deleted_(0),
      resizable_(o.resizable_),
      hash_(o.hash_),
      equals_(o.equals_)
  {
    for(size_t i = 0; i < capacity_; ++i) {
      new (buckets_ + i) Bucket();
    }
    insert(o.buckets_, o.buckets_ + o.capacity_, /*overwrite*/false);
  }

  HashMap &operator=(const HashMap &o)
  {
    HashMap tmp(capacity_, resizable_, mm_);
    tmp.insert(o.buckets_, o.buckets_ + o.capacity_, /*overwrite*/false);
    swap(tmp);
    return *this;
  }

  ~HashMap()
  {
    release();
  }

  void release()
  {
    for(size_t i = 0; i < capacity_; ++i) {
      buckets_[i].~Bucket();
    }
    if(buckets_ != (Bucket*)inlineBuckets_)
      mm_->deallocate(buckets_);
  }

  /// Overwrites the entry if it already exists
  inline void put(const KEY &key, const VALUE &value)
  {
    put(key, hash_(key), value);
  }
  inline void put(const KEY &key, size_t hash, const VALUE &value)
  {
    if(resizable_ && (count_ * 4) >= (capacity_ * 3))
      resize(nextCapacity(capacity_));

    do_insert(key, value, hash, /*overwrite*/true);
  }
  inline void putAll(const HashMap &o)
  {
    if(resizable_ && ((count_ + o.size()) * 4) >= (capacity_ * 3))
      resize(nextCapacity(capacity_ + o.size()));

    insert(o.buckets_, o.buckets_ + o.capacity_, /*overwrite*/true);
  }

  /// Adds a duplicate entry if it already exists
  inline void add(const KEY &key, const VALUE &value)
  {
    add(key, hash_(key), value);
  }
  inline void add(const KEY &key, size_t hash, const VALUE &value)
  {
    if(resizable_ && (count_ * 4) >= (capacity_ * 3))
      resize(nextCapacity(capacity_ + 1));

    do_insert(key, value, hash, /*overwrite*/false);
  }
  inline void addAll(const HashMap &o)
  {
    if(resizable_ && (count_ * 4) >= (capacity_ * 3))
      resize(nextCapacity(capacity_ + o.size()));

    insert(o.buckets_, o.buckets_ + o.capacity_, /*overwrite*/false);
  }

  inline const VALUE *get(const KEY &key) const
  {
    return get(key, hash_(key));
  }
  inline const VALUE *get(const KEY &key, size_t hash) const
  {
    bool found;
    Bucket *ptr = find(key, hash, found);
    return found ? &ptr->value : 0;
  }

  inline void remove(const KEY &key)
  {
    return remove(key, hash_(key));
  }
  inline void remove(const KEY &key, size_t hash)
  {
    iterator i = find(key, hash);
    while(i != end()) remove(i);
  }

  void remove(iterator &i)
  {
    if(i.ptr_ != i.end_) {
      Bucket *tmp = i.ptr_;
      ++i;
      if(tmp->state == Bucket::OCCUPIED) {
        tmp->setToDelete();
        ++deleted_;
      }
    }
  }

  inline bool contains(const KEY &key) const
  {
    return contains(key, hash_(key));
  }
  inline bool contains(const KEY &key, size_t hash) const
  {
    bool found;
    find(key, hash, found);
    return found;
  }

  inline iterator begin()
  {
    return iterator(buckets_, buckets_ + capacity_);
  }

  inline iterator end()
  {
    return iterator(buckets_ + capacity_, buckets_ + capacity_);
  }

  // Returns an iterator over the duplicate items equal to key
  inline iterator find(const KEY &key)
  {
    return find(key, hash_(key));
  }
  inline iterator find(const KEY &key, size_t hash)
  {
    bool found;
    Bucket *ptr = find(key, hash, found);
    return found ? iterator(ptr, buckets_ + capacity_, this) : end();
  }

  inline size_t getHash(const KEY &key)
  {
    return hash_(key);
  }

  inline size_t size() const { return count_ - deleted_; }
  inline size_t capacity() const { return capacity_; }
  inline bool isEmpty() const { return count_ == deleted_; }
  inline bool isResizeable() const { return resizable_; }

  inline void resize(size_t newCapacity)
  {
    HashMap tmp(newCapacity, resizable_, mm_, hash_, equals_);
    tmp.insert(buckets_, buckets_ + capacity_, /*overwrite*/false);
    swap(tmp);
  }

  inline void removeAll()
  {
    HashMap tmp(capacity_, resizable_, mm_, hash_, equals_);
    swap(tmp);
  }

  inline void swap(HashMap &o)
  {
    Bucket *b;
    size_t s;
    bool bl;
    XERCES_CPP_NAMESPACE_QUALIFIER MemoryManager *m;
    char space[sizeof(inlineBuckets_)];

    b = buckets_; buckets_ = o.buckets_; o.buckets_ = b;
    b = lastKnownEmpty_; lastKnownEmpty_ = o.lastKnownEmpty_; o.lastKnownEmpty_ = b;

    if(buckets_ == (Bucket*)o.inlineBuckets_ ||
       o.buckets_ == (Bucket*)inlineBuckets_) {
      memcpy(space, inlineBuckets_, sizeof(inlineBuckets_));

      if(buckets_ == (Bucket*)o.inlineBuckets_) {
        memcpy(inlineBuckets_, o.inlineBuckets_, sizeof(inlineBuckets_));
        buckets_ = (Bucket*)inlineBuckets_;
        lastKnownEmpty_ = lastKnownEmpty_ -
          ((Bucket*)o.inlineBuckets_) + (Bucket*)inlineBuckets_;
      }
      if(o.buckets_ == (Bucket*)inlineBuckets_) {
        memcpy(o.inlineBuckets_, space, sizeof(inlineBuckets_));
        o.buckets_ = (Bucket*)o.inlineBuckets_;
        o.lastKnownEmpty_ = o.lastKnownEmpty_ -
          ((Bucket*)inlineBuckets_) + (Bucket*)o.inlineBuckets_;
      }

    }

    s = capacity_; capacity_ = o.capacity_; o.capacity_ = s;
    s = attic_; attic_ = o.attic_; o.attic_ = s;
    s = count_; count_ = o.count_; o.count_ = s;
    s = deleted_; deleted_ = o.deleted_; o.deleted_ = s;
    bl = resizable_; resizable_ = o.resizable_; o.resizable_ = bl;
    m = mm_; mm_ = o.mm_; o.mm_ = m;
  }

  inline void printDebug(std::ostream &out) const
  {
    size_t links = 0;
    Bucket *ptr = buckets_;
    Bucket *end = buckets_ + capacity_;
    while(ptr != end) {
      out << (ptr - buckets_) << ": "
          << "(" << (ptr->state == Bucket::EMPTY ? "e" : (ptr->state == Bucket::OCCUPIED ? "o" : "d")) << ") "
          << ptr->key << " -> "
          << ptr->value << " [";
      if(ptr->next == 0) out << "null]\n";
      else {
        ++links;
        out << (ptr->next - buckets_) << "]\n";
      }
      ++ptr;
    }

    out << "-- count: " << count_ << ", deleted: " << deleted_ << ", links: " << links << "\n";
  }

private:
  inline Bucket *find(const KEY &key, size_t h, bool &found) const
  {
    found = false;

    Bucket *ptr = &buckets_[h & (attic_ - 1)];
    if(ptr->state != Bucket::EMPTY) {
      while(true) {
        if(ptr->state == Bucket::OCCUPIED && ptr->hash == h && equals_(key, ptr->key)) {
          found = true;
          break;
        }
        if(ptr->next == 0) break;
        ptr = ptr->next;
      }
    }

    return ptr;
  }

  inline Bucket *findNextDuplicate(Bucket *prev)
  {
    if(prev == buckets_ + capacity_) return prev;

    Bucket *ptr = prev->next;
    while(ptr) {
      if(ptr->state == Bucket::OCCUPIED && ptr->hash == prev->hash && equals_(prev->key, ptr->key))
        return ptr;
      ptr = ptr->next;
    }

    return buckets_ + capacity_;
  }

  inline void do_insert(const KEY &key, const VALUE &value, size_t h, bool overwrite)
  {
    bool found;
    Bucket *ptr = find(key, h, found);

    if(found) {
      if(overwrite) {
        // No duplicates - overwrite the existing key
        ptr->set(key, value, h);
        return;
      }
      // Find the end of the chain, so that we can add the duplicate
      while(ptr->next != 0) {
        ptr = ptr->next;
      }
    }
    else if(ptr->state == Bucket::EMPTY) {
      ++count_;
      ptr->set(key, value, h);
      return;
    }
    
    // Find an empty bucket - start looking where we last found one
    --lastKnownEmpty_;
    while(lastKnownEmpty_->state != Bucket::EMPTY) {
      if(lastKnownEmpty_ == buckets_) {
        assert(false);
        return;
      }
      --lastKnownEmpty_;
    }

    // Link the empty bucket into the chain for the hash value
    ++count_;
    lastKnownEmpty_->set(key, value, h);
    ptr->next = lastKnownEmpty_;
  }

  inline void insert(Bucket *s, Bucket *e, bool overwrite)
  {
    for(; s != e; ++s) {
      if(s->state == Bucket::OCCUPIED)
        do_insert(s->key, s->value, s->hash, overwrite);
    }
  }

  XERCES_CPP_NAMESPACE_QUALIFIER MemoryManager *mm_;

  Bucket *buckets_;
  size_t capacity_, attic_;
  Bucket *lastKnownEmpty_;

  size_t count_, deleted_;
  bool resizable_;

  HASH hash_;
  EQUALS equals_;

  char inlineBuckets_[sizeof(Bucket) * UNALLOCATED_SIZE];
};

#endif
