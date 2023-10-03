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

#ifndef __BASICMEMORYMANAGER_HPP
#define __BASICMEMORYMANAGER_HPP

#include <xercesc/framework/MemoryManager.hpp>

class XQILLA_API BasicMemoryManager : public XERCES_CPP_NAMESPACE_QUALIFIER MemoryManager
{
public:
  static inline MemoryManager *get() {
    static BasicMemoryManager instance;
    return &instance;
  }

#if _XERCES_VERSION >= 30000
  void* allocate(XMLSize_t numElements)
#else
  void* allocate(size_t numElements)
#endif  
	{ return ::malloc(numElements); }
	void deallocate(void *p) { ::free(p); }
	MemoryManager *getExceptionMemoryManager() { return get(); }
};

#endif

