/*
  Copyright 2009 by James Dean Palmer and others.
  Copyright 2008 by Abe Pralle.
 
  Ginger is free software.  You can redistribute and/or modify
  this work under ther terms of the Apache License Version 2.0
  or, at your option, Ginger's amended LGPL 2.1 license.  You may
  not use this file except in compliance with one of these licenses.
  You may also obtain a copy of the Apache License at
 
    http://www.apache.org/licenses/LICENSE-2.0
 
  You may obtain a copy of Ginger's amended LGPL License at:
 
    http://ging3r.org/licenses/LGPL-2.1.txt
 
  Unless required by applicable law or agreed to in writing, 
  software distributed under the License is distributed on an 
  "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, 
  either express or implied. See the License(s) for the specific 
  language governing permissions and limitations.
 
  Please report all bugs and problems to "bugs@ging3r.org".
*/

#ifndef SLAG_MM
#define SLAG_MM
//====================================================================
//  slag_mm.h
//  
//  Slag Memory Manager
//
//  Strategy
//  
//  For small allocations of (default: 1k or less), a custom 
//  "fast heap" is used:
//
//    - There are two banks of fast heap memory.  The one that is 
//      actively used for allocations is called Alpha; the other is
//      called Beta.
//
//    - A cursor starts out at position 0 on Alpha.  Every allocation
//      of N bytes advances the cursor by N+4 bytes.  The 4-byte
//      size of the allocation is written to m+0 and a pointer to m+4
//      is returned.
//
//    - The first time Alpha fills up, Alpha becomes Beta and the
//      second page becomes the new Alpha.  Operations proceed
//      normally.
//
//    - Every successive time Alpha fills up, a data collection
//      is triggered:
//
//      Every reachable object is traced through during a data
//      collection.  If the object falls inside page Alpha it is
//      ignored.  If it falls inside page Beta, it considered a
//      long-lived object.  Space is reallocated using OS 'new'
//      (and the byte size at ptr-4) and the object data is copied 
//      over.  The byte size is cleared to contain (-1) to indicate
//      that memory has already been copied, and the pointer to the
//      new, semi-permanent memory is placed at ptr+0.
//
//      After the collection, Alpha becomes Beta and Beta becomes
//      cleared to a fresh Alpha, ready for more allocations.
//
//  For large allocations of more than 1k and for fast allocations 
//  that are surviving their second data collection, system
//  allocation is used via 'new'.  It works thus:
//
//    - A header on every allocation indicates whether or not the 
//      allocation has been visited during the current collection 
//      and has a link to the next allocation.  After a collection,
//      unvisited allocations are freed. 
//
//    - During a collection (triggered by Alpha filling up), every 
//      pointer that doesn't lie within pages Alpha or Beta is 
//      assumed to be system-allocated memory (set up by the MM) 
//      and thus visited.
//
//  ------------------------------------------------------------------

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

// MM_DEFAULT_FAST_PAGE_SIZE
//
// 5 MB default fast memory page size.  Two of these will be
// allocated for a total of 10MB.  Larger sizes result in less 
// frequent data collections with no other impact besides
// the use of the memory itself.  Smaller allocations are certainly
// viable when memory is tight.
#define  MM_DEFAULT_FAST_PAGE_SIZE (5*1024*1024)


// MM_FAST_HEAP_THRESHOLD
//
// IMPORTANT: do not set the threshold above 32767 without increasing
// the data size of num_bytes in MMFastAllocHeader.
//
// The size limit (in bytes) for an allocation to be placed
// on the fast heap rather than directly into a system allocation.
//
// This is also the size limit of how many bytes may need to be
// copied over per single long-lived object.  Larger sizes will
// make the program faster only IF objects of the larger size 
// are usually short-lived.  If they're more often long-lived,
// the program will run slower due to frequent recopying.
// This value should always been some fraction of the 
// fast_heap_page_size - the heap threshold vs the page size
// should be a fraction of (a guess here:) 1/100 or smaller.
#if !defined(MM_FAST_HEAP_THRESHOLD)
#define  MM_FAST_HEAP_THRESHOLD 1024
#endif

// Uncomment the following line to have the memory manager ensure 
// that each returned allocation is cleared first.
// #define MM_CLEAR_ALLOCATIONS

//#include <cstdio>
//#include <iostream>
//using namespace std;

//struct MMError
//{
//  const char* mesg;
//
//  MMError( const char* mesg ) { this->mesg = mesg; }
//};

typedef struct {
  short num_bytes;
  short visited;
} MMFastAllocHeader;

typedef struct MMSysAllocHeader_t {
  short num_bytes;
  short visited;
  short requires_cleanup;
  struct MMSysAllocHeader_t* next;
} MMSysAllocHeader;

typedef struct SlagMemoryManager_t {
  char* fast_heap_alpha;
  char* fast_heap_beta;

  // not set until collection starts
  char* fast_heap_alpha_end;
  char* fast_heap_beta_end;

  char* alpha_allocation_cursor;
  int   alpha_remaining_bytes;

  void (*collection_callback)(struct SlagMemoryManager_t* data);
  void* collection_data;

  int   system_allocations_since_last_collection;
  int   allocations_since_last_collection;
  int   fast_heap_allocations;
  int   system_allocations;
  int   collections;

  int   fast_heap_page_size;

  // We get one free primary/secondary heap exchange until we've
  // filled both our pages.  This puts an irregularity in the process,
  // but at the same time a program that only ever uses between
  // 1 and 2 pages of fast heap will run faster, and ones that need
  // more should resign themselves to regular collections anyways.
  short beta_still_unused;

  // Items on the long_lived_list not referenced during a collection
  // are freed at the end of the collection.
  MMSysAllocHeader* long_lived_list;

  // Allocations pending cleanup are unreferenced but need to have
  // their cleanup method called.
  MMSysAllocHeader* pending_cleanup;

  // Items on the persistent_list do not need to be referenced 
  // during collections and are only freed at the end of the program.
  MMSysAllocHeader* persistent_list;

  //  SlagMemoryManager();
  //  ~SlagMemoryManager();

  /*
  void init( int fast_heap_page_size=MM_DEFAULT_FAST_PAGE_SIZE );

  inline bool collection_required_before_allocation( int num_bytes )
  {
    return !( num_bytes <= alpha_remaining_bytes 
        || num_bytes > MM_FAST_HEAP_THRESHOLD
        || beta_still_unused);
  }
  */

  //void* allocate( int num_bytes );
  //void* allocate_system( int num_bytes );
  //void* allocate_persistent( int num_bytes );
  //void  free_list( MMSysAllocHeader* list );
  //void  free_managed_memory();
  //void  shut_down();
  //void  begin_collection();

  ////////////////////////////////////////////////////////////////////
  //  reference()
  //
  //    ptr:
  //      The memory address of the variable that's pointing to an 
  //      object.  This function may change that pointer.
  //
  //    bool return value:
  //      True if the collector picks up this object for the first
  //      time - in which case the calling code should descend into
  //      the object data and reference all the pointers in there.
  //
  //      False if the object memory has already been referenced or
  //      if there's a null pointer.  No further action needs to be
  //      taken either way.
  ////////////////////////////////////////////////////////////////////
  //bool reference( char** ptr );

  //void end_collection();

  // Mark the given existing allocation as requiring cleanup.  This
  // MUST be a "system" allocation and not a fast heap allocation.
  // When an object requiring cleanup is no longer referenced, it
  // is added to the pending_cleanup list.  Once cleanup() has been
  // called, the object is marked as NOT requiring cleanup and is
  // put back into the system.  If it has no references a second time
  // around it will be actually deleted.
  //void mark_as_requiring_cleanup( void* ptr );

  // returns: 
  //   0 if no unreferenced allocations are requiring cleanup.
  //   Otherwise marks the next pending allocation as visited but
  //   not requiring cleanup, adds it to the long_lived_list, and 
  //   returns it - it'll take another GC before the item gets 
  //   permanently deleted.
  //void *get_next_pending_cleanup();

} SlagMemoryManager;


void slag_mm_init (SlagMemoryManager* mm, int fast_heap_page_size);
void slag_mm_set_collection_callback(SlagMemoryManager*mm, void(*callback)(SlagMemoryManager*));



#endif //SLAG_MM

