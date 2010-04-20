/*
  Copyright 2009 by James Dean Palmer and others.
  Copyright 2008 by Abe Pralle.

  Licensed under the Apache License, Version 2.0 (the "License");
  you may not use this file except in compliance with the License.
  You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

  Please report all bugs and problems to "bugs@ging3r.org".
*/

#include "ginger.h"
#include <assert.h>

#define GC_CLEAR_ALLOCATIONS 1

void gc_free_managed_memory(GarbageCollector* mm);

static int gc_system_xfers = 0;
static int gc_free_alloc = 0;

static int  stat_str8 = 0;
static int stat_vector = 0;
static int  stat_cons = 0;
static int  stat_function = 0;
static int stat_binary = 0;
static int  stat_dict = 0;
static int stat_dict_cell = 0;
static int  stat_type = 0;
static int  stat_float = 0;
static int  stat_stream = 0;
static int  stat_string_stream = 0;
static int  stat_other = 0;


GarbageCollector* gc_new (int page_size) {
  GarbageCollector* mm = (GarbageCollector*)malloc(sizeof(GarbageCollector));
  memset(mm, 0, sizeof(GarbageCollector));

  mm->fast_heap_page_size = page_size;

  mm->fast_heap_alpha = malloc(page_size);
  assert(mm->fast_heap_alpha != 0);
  memset(mm->fast_heap_alpha, 0, page_size);

  mm->fast_heap_beta = malloc(page_size);
  assert(mm->fast_heap_beta != 0);
  memset(mm->fast_heap_beta,  0, page_size);

  mm->fast_heap_alpha_end = mm->fast_heap_alpha + mm->fast_heap_page_size;
  mm->fast_heap_beta_end = mm->fast_heap_beta  + mm->fast_heap_page_size;

  mm->alpha_allocation_cursor = mm->fast_heap_alpha;
  mm->alpha_remaining_bytes = (page_size - sizeof(GCFastAllocHeader)) - 4;
  mm->beta_still_unused = 1;

  return mm;
}

void gc_shut_down (GarbageCollector* mm) {
  gc_free_managed_memory(mm);

  if (mm->fast_heap_alpha != 0) {
    free(mm->fast_heap_alpha);
    mm->fast_heap_alpha = 0;
  }

  if (mm->fast_heap_beta != 0) {
    free(mm->fast_heap_beta);
    mm->fast_heap_beta = 0;
  }

}

void* gc_allocate(GarbageCollector* mm, int num_bytes) {
  assert (num_bytes > 0);
  mm->allocations_since_last_collection++;

  if (num_bytes <= GC_FAST_HEAP_THRESHOLD) {
    // fast heap allocation
    if (num_bytes > mm->alpha_remaining_bytes) {
      if (mm->beta_still_unused) {
        // Swap the pages
        mm->beta_still_unused = 0;
        void* temp = mm->fast_heap_alpha;
        mm->fast_heap_alpha = mm->fast_heap_beta;
        mm->fast_heap_beta = temp;
        mm->alpha_allocation_cursor = mm->fast_heap_alpha;
        mm->alpha_remaining_bytes = mm->fast_heap_page_size - sizeof(GCFastAllocHeader);
        mm->fast_heap_alpha_end = mm->fast_heap_alpha + mm->fast_heap_page_size;
        mm->fast_heap_beta_end = mm->fast_heap_beta  + mm->fast_heap_page_size;
      } else {
        if (mm->collection_callback) {
          mm->collection_callback(mm);
          void* t = gc_allocate(mm, num_bytes);
          return t;
        } else {
          printf("GC:: The memory manager required a collection before the current allocation request!");
          exit(1);
        }
      }
    }

    char* result = mm->alpha_allocation_cursor;
    int num_bytes_original = num_bytes;

    // store the allocation size as a header before the client space
    ((GCFastAllocHeader*) result)->num_bytes = num_bytes;
    ((GCFastAllocHeader*) result)->visited = 0;

    num_bytes += sizeof(GCFastAllocHeader);
    // round out num_bytes to a multiple of 4 for data alignment purposes
    num_bytes = (num_bytes + 3) & ~3;

    mm->alpha_remaining_bytes   -= num_bytes;
    mm->alpha_allocation_cursor += num_bytes;

    result    += sizeof(GCFastAllocHeader);
    return result;
  } else {

    // printf("SYSALLOC %d\n", num_bytes);

    if (mm->system_allocations_since_last_collection > 200)
      mm->collection_callback(mm);

    // system allocation
    ++mm->system_allocations_since_last_collection;
    char* result = (void*)malloc(num_bytes + sizeof(GCSysAllocHeader));
    if ( !result ) {
      printf("Out of memory!");
      exit(1);
    }
    bzero(result, num_bytes + sizeof(GCSysAllocHeader));

    GCSysAllocHeader* mem = (GCSysAllocHeader*) result;
    mem->visited = 0;
    //mem->active = 1;
    mem->num_bytes = num_bytes;
    mem->requires_cleanup = 0;
    mem->next = mm->long_lived_list;
    mm->long_lived_list = mem;

    // scoot the result pointer past the header link info
    result += sizeof(GCSysAllocHeader);
    return result;
  }
}

void* gc_allocate_system (GarbageCollector* mm, int num_bytes) {
  assert (num_bytes > 0);
  // Puts something in semi-permanent system storage to begin with.
  // Note that this must still be referenced during
  // every garbage collection or it will be freed.  For hands-off
  // storage that's only deallocated at the end of the program,
  // use allocate_persistent instead.
  mm->system_allocations_since_last_collection += 1;

  char* result = (void*)malloc(num_bytes + sizeof(GCSysAllocHeader));
  if ( !result ) {
    printf("Out of memory.");
    exit(1);
  }

  GCSysAllocHeader* mem = (GCSysAllocHeader*) result;
  mem->visited = 0;
  //mem->active = 1;
  mem->num_bytes = num_bytes;
  mem->requires_cleanup = 0;
  mem->next = mm->long_lived_list;
  mm->long_lived_list = mem;

  // scoot the result pointer past the header link info
  result += sizeof(GCSysAllocHeader);
  bzero(result, num_bytes);
  //memset (result, 0, num_bytes);
  //printf("ALLOC %d\n", result);
  return result;
}

void* gc_allocate_persistent (GarbageCollector* mm, int num_bytes) {
  assert (num_bytes > 0);
  // The memory returned from this is never traced or freed until
  // the memory manager is shut down.
  char* result = (void*)malloc(sizeof(char)*num_bytes + sizeof(GCSysAllocHeader));
  if (!result) {
    printf("Out of memory.");
    exit(1);
  }

  GCSysAllocHeader* mem = (GCSysAllocHeader*) result;
  mem->visited = 0;
  //mem->active = 1;
  mem->num_bytes = num_bytes;
  mem->requires_cleanup = 0;
  mem->next = mm->persistent_list;
  mm->persistent_list = mem;

  // scoot the result pointer past the header link info
  result += sizeof(GCSysAllocHeader);
  return result;
}

static void gc_free_list (GCSysAllocHeader* list) {
  GCSysAllocHeader* cur = list;

  while (cur != 0) {
    GCSysAllocHeader* next = cur->next;
    free(cur);
    cur = next;
  }
}

void gc_free_managed_memory(GarbageCollector* mm) {
  mm->beta_still_unused = 1;
  mm->alpha_allocation_cursor = mm->fast_heap_alpha;
  mm->alpha_remaining_bytes = (mm->fast_heap_page_size - sizeof(GCFastAllocHeader)) - 4;
  //memset(mm->fast_heap_alpha, 0, mm->fast_heap_page_size);

  gc_free_list(mm->long_lived_list);
  mm->long_lived_list = 0;
  gc_free_list(mm->persistent_list);
  mm->persistent_list = 0;
}

void gc_begin_collection(GarbageCollector* mm) {
  mm->system_allocations_since_last_collection = 0;
  mm->allocations_since_last_collection = 0;
  mm->fast_heap_allocations = 0;
}

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

short gc_reference(GarbageCollector* mm, void** ptr ) {
  char* addr = *ptr;
  if (addr == 0) return 0;

  if ((addr >= mm->fast_heap_beta) && (addr < mm->fast_heap_beta_end)) {

    // If the ptr is on the beta page then we need to move it to
    // long term storage.

    GCFastAllocHeader* header = (GCFastAllocHeader*)(addr - sizeof(GCFastAllocHeader));
    int num_bytes = header->num_bytes;
    assert(num_bytes != 0);

    if (num_bytes == -1) {

      // We have already collected this data. **ptr contains the new
      // address that *ptr should be reset to.

      *ptr = *((void**)addr);
      return 0;

    } else {

      // Collect the data and copy to a system allocation.

      char* result = (void*)malloc(num_bytes + sizeof(GCSysAllocHeader));
      if ( !result ) {
        printf("Out of memory.");
        assert(0);
      }

      GCSysAllocHeader* mem = (GCSysAllocHeader*) result;
      mem->visited = 1;
      //mem->active = 1;
      mem->requires_cleanup = 0;
      mem->next = mm->long_lived_list;
      mem->num_bytes = num_bytes;
      mm->long_lived_list = mem;
      gc_system_xfers++;

      // scoot the result pointer past the header link info
      result += sizeof(GCSysAllocHeader);
      memcpy(result, addr, num_bytes);

      // Mark the #bytes as -1 to indicate it's been copied.
      header->num_bytes = -1;

      // Place new address in old location so we know it when we see it again
      *(void**)addr = result;

      // update calling address
      *ptr = result;

      return 1;
    }

  } else if (addr >= mm->fast_heap_alpha && addr < mm->fast_heap_alpha_end) {

    // Referencing the most recent page of fast heap; no collection
    // performed, but the first one to reference this data should
    // go on the reference its internals.
    GCFastAllocHeader* header = (GCFastAllocHeader*)(addr - sizeof(GCFastAllocHeader));
    if (header->visited) {
      //printf(":debug GC gc_reference 2.1 return\n");
      return 0;
    } else {
      //printf(":debug GC gc_reference 2.2 return\n");
      mm->fast_heap_allocations++;
      header->visited = 1;
      return 1;
    }

  } else {

    // Address isn't on Alpha or Beta fast heap pages; it must be
    // allocated in system memory.  There's no question of collection
    // (the data remains where it is), but we need to mark it as
    // referenced so it won't be freed later and, if it's the first
    // time we've seen it this collection, signal that it should be
    // traced into.

    GCSysAllocHeader* header = (GCSysAllocHeader*)(addr - sizeof(GCSysAllocHeader));

    //printf(":debug GC !!!\n");
    if (header->visited) {
      //printf(":debug GC gc_reference 3.1 return\n");
      return 0;
    } else {
      //printf(":debug GC gc_reference 3.2 return\n");
      header->visited = 1;
      return 1;
    }

  }
  //printf(":debug GC Some kind of ERROR\n");
  assert(0);
}

// Debugging code..
void gc_analyze(GarbageCollector* mm, void* addr0) {
  char* addr = addr0;
  if (addr >= mm->fast_heap_alpha && addr < mm->fast_heap_alpha_end) {
    printf("analyze: is alpha\n");
    return;
  }
  if (addr >= mm->fast_heap_beta && addr < mm->fast_heap_beta_end) {
    printf("analyze: is beta\n");
    return;
  }
  GCSysAllocHeader* mem = mm->long_lived_list;
  while (mem != 0) {
    if ((char*)(mem + 1) == addr) {
//    if ((char*)(mem + sizeof(GCSysAllocHeader)) == addr) {
      int i=0;
      int n = gc_size(mm, addr);
      printf("analyze: is long lived\n");
      printf("analyze: size is %d\n", n);
      for (i = 0; i < n; i+=4) {
        print_bits32(*((unsigned long*)(addr+i)));
      }
      return;
    }
    mem = mem->next;
  }
  printf("alpha begin %d\n", mm->fast_heap_alpha);
  printf("alpha end %d\n", mm->fast_heap_alpha_end);
  printf("beta begin %d\n", mm->fast_heap_beta);
  printf("beta end %d\n", mm->fast_heap_beta_end);

  printf("analyze: is what??? %d\n", addr);
  assert(0);
}

void gc_end_collection(GarbageCollector* mm) {
  mm->collections++;
  // We will count the number of system allocations below..
  mm->system_allocations = 0;

  // Swap the alpha and beta pages and clear the new alpha.
  void* temp = mm->fast_heap_alpha;
  mm->fast_heap_alpha = mm->fast_heap_beta;
  mm->fast_heap_beta = temp;
  mm->alpha_allocation_cursor = mm->fast_heap_alpha;
  mm->alpha_remaining_bytes = (mm->fast_heap_page_size - sizeof(GCFastAllocHeader)) - 4;

  mm->fast_heap_alpha_end = mm->fast_heap_alpha + mm->fast_heap_page_size;
  mm->fast_heap_beta_end = mm->fast_heap_beta  + mm->fast_heap_page_size;

  bzero(mm->fast_heap_alpha, mm->fast_heap_page_size);

  // Beta is available once more..
  mm->beta_still_unused = 0;

  // Free or move to pending_cleanup any unvisited items in the
  // long_lived_list.
  if (mm->long_lived_list != 0) {
    // Start just after the head of the list so we don't have
    // to keep checking for it as a special case whenever
    // we delete something
    GCSysAllocHeader* prev = mm->long_lived_list;
    GCSysAllocHeader* cur  = mm->long_lived_list->next;

    while (cur) {
      if (cur->visited) {
        prev = cur;
        cur->visited = 0;
        cur = cur->next;
        mm->system_allocations++;

      } else if (cur->requires_cleanup) {

        // TODO - call clean up function

        GIN_OBJ object_to_del = (void*)cur + sizeof(GCSysAllocHeader);

        // given a ginger object get the GingerType
        GingerType *obj_type = GIN_NIM_GET_TYPE_OBJECT(object_to_del);

        // TODO - uncomment the function pointer call
        // check if there is a function pointer
        // call c_unmake and pass it the foreign of the gin object
        //(*(obj_type->c_unmake))(GIN_NIM_GET_FOREIGN(object_to_del));

        // This is untested.
        //assert(0);
        GCSysAllocHeader* next = cur->next;
        prev->next = next;
        cur->next = mm->pending_cleanup;
        mm->pending_cleanup = cur;
        //printf("FREE PENDING %d\n", ((char*)cur)+sizeof(GCSysAllocHeader));
        cur = next;

      } else {

        gc_free_alloc++;
        GCSysAllocHeader* next = cur->next;
        prev->next = next;
        //printf("FREE %d\n", ((char*)cur)+sizeof(GCSysAllocHeader));
        free(cur);
        cur = next;

      }
    }

    // Visit the head of the list last since we'll only have to
    // change the start pointer once (at most) as a special case.
    if (mm->long_lived_list->visited) {
      mm->long_lived_list->visited = 0;
    }
    else if (mm->long_lived_list->requires_cleanup)
    {
      // TODO - call clean up function

      //GIN_OBJ object_to_del = (void*)cur + sizeof(GCSysAllocHeader);

      // given a ginger object get the GingerType
      //GingerType *obj_type = GIN_NIM_GET_TYPE_OBJECT(object_to_del);

      // TODO - uncomment the function pointer call
      // check if there is a function pointer
      // call c_unmake and pass it the foreign of the gin object
      //(*(obj_type->c_unmake))(GIN_NIM_GET_FOREIGN(object_to_del));


      // This is untested.
      assert(0);
      GCSysAllocHeader* next = mm->long_lived_list->next;
      mm->long_lived_list->next = mm->pending_cleanup;
      mm->pending_cleanup = mm->long_lived_list;
      mm->long_lived_list = next;
    } else {
      GCSysAllocHeader* next = mm->long_lived_list->next;
      free(mm->long_lived_list);
      mm->long_lived_list = next;
    }
  }
}

void gc_mark_as_requiring_cleanup(GarbageCollector* mm, void* ptr) {
  GCSysAllocHeader* header = (GCSysAllocHeader*) (ptr - sizeof(GCSysAllocHeader));
  header->requires_cleanup = 1;
}

void* gc_get_next_pending_cleanup(GarbageCollector* mm) {
  if (mm->pending_cleanup == 0) return 0;

  GCSysAllocHeader* m = mm->pending_cleanup;
  mm->pending_cleanup = mm->pending_cleanup->next;
  m->next = mm->long_lived_list;
  mm->long_lived_list = m;
  m->visited = 1;
  m->requires_cleanup = 0;
  return (m + 1);
}

void gc_set_collection_callback(GarbageCollector*mm, void(*callback)(GarbageCollector*)) {
  ((GarbageCollector*)mm)->collection_callback = callback;
}

short gc_collection_required_before_allocation(GarbageCollector*mm, int num_bytes) {
  return !( num_bytes <= mm->alpha_remaining_bytes
            || num_bytes > GC_FAST_HEAP_THRESHOLD
            || mm->beta_still_unused);
}

unsigned long gc_size(GarbageCollector* mm, void *addr0) {
  char* addr = addr0;
  if ( ((addr >= mm->fast_heap_beta) && (addr < mm->fast_heap_beta_end)) ||
       ((addr >= mm->fast_heap_alpha) && (addr < mm->fast_heap_alpha_end)) ) {
    GCFastAllocHeader* n = (GCFastAllocHeader*)(addr - sizeof(GCFastAllocHeader));
    assert(n->num_bytes != 0);
    return n->num_bytes;
  }

  GCSysAllocHeader* n = (GCSysAllocHeader*)(addr - sizeof(GCSysAllocHeader));
  //if (n->active == 0) {
  //  return 0;
  //}
  return n->num_bytes;
}

unsigned long gc_active(GarbageCollector* mm, void *addr0) {
  char* addr = addr0;
  if ( ((addr >= mm->fast_heap_beta) && (addr < mm->fast_heap_beta_end)) ||
       ((addr >= mm->fast_heap_alpha) && (addr < mm->fast_heap_alpha_end)) ) {
    return 1;
  }

  GCSysAllocHeader* n = (GCSysAllocHeader*)(addr - sizeof(GCSysAllocHeader));
  //if (n->active == 0) {
  //return 0;
  //}
  return 1;
}

// Ginger specific functionality

void reference_frame(GarbageCollector* mm, Frame_Narg* frame);

void reference_var(GarbageCollector* mm, GIN_OBJ o) {
  int i;

  // We should never reference uninitialized memory.
  assert(o != 0);

  // We should never reference immediates
  assert(GIN_IS_IM(o) == 0);

  // Now consider the fundamental types:

  //
  // Strings
  //

  if (GIN_IS_STR8(o)) {

    stat_str8++;

#ifdef GC_DEBUG
    printf("reference_var: STRING %s %d\n", GIN_STR_VALUE(o), GIN_STR_LENGTH(o));
#endif
    gc_reference(mm, (void**)&(((GingerObject*)(o))->str8_value));
    return;
  }

  //
  // Vectors
  //

  if (GIN_IS_VECTOR(o)) {

    stat_vector++;

#ifdef GC_DEBUG
    printf("reference_var: VECTOR\n");
    printf("VECTOR length=%d\n", ((GingerVector*)(o))->length);
#endif
    for (i=0; i<((GingerVector*)(o))->length; i++) {
      GIN_OBJ x = ((GingerVector*)(o))->value[i];
      GIN_OBJ y = x;
      if (x && (!GIN_IS_IM(x)) && (gc_reference(mm, &(((GingerVector*)(o))->value[i])))) {
        x = ((GingerVector*)(o))->value[i];
        reference_var(mm, x);
      }
    }
    if (((GingerVector*)(o))->length > 0) {
      gc_reference(mm, (void**)&(((GingerVector*)(o))->value));
    }

#ifdef GC_DEBUG
    printf("reference_var: VECTOR DONE\n");
#endif
    return;
  }

  //
  // Cons Cells
  //

  if (GIN_IS_CONS(o)) {

    stat_cons++;

#ifdef GC_DEBUG
    printf("reference_var: CONS\n");
#endif
    GIN_OBJ x = GIN_NIM_GET_F0(o);
    GIN_OBJ y = x;

#ifdef GC_DEBUG
    if (GIN_IS_IM(x)) {
         printf("f0=");
         print_bits32(x);
    }
#endif

    if (x && (!GIN_IS_IM(x)) && (gc_reference(mm, &(GIN_NIM_GET_F0(o))))) {
      x = GIN_NIM_GET_F0(o);
      reference_var(mm, x);
    }

    x = GIN_NIM_GET_F1(o);
    y = x;

#ifdef GC_DEBUG
    if (GIN_IS_IM(x)) {
         printf("f1=");
         print_bits32(x);
    }
#endif

    if (x && (!GIN_IS_IM(x)) && (gc_reference(mm, &(GIN_NIM_GET_F1(o))))) {
      x = GIN_NIM_GET_F1(o);
      reference_var(mm, x);
    }

    x = GIN_NIM_GET_F2(o);
    y = x;

#ifdef GC_DEBUG
    if (GIN_IS_IM(x)) {
         printf("f2=");
         print_bits32(x);
    }
#endif

    if (x && (!GIN_IS_IM(x)) && (gc_reference(mm, &(GIN_NIM_GET_F2(o))))) {
      x = GIN_NIM_GET_F2(o);
      reference_var(mm, x);
    }

#ifdef GC_DEBUG
    printf("end of cons stuff\n");
#endif

    return;
  }

  //
  // Functions
  //

  if (GIN_IS_FUNCTION(o)) {

    stat_function++;

#ifdef GC_DEBUG
    printf("reference_var: FUNCTION\n");
#endif
    if (gc_active(mm, ((GingerObject*)(o))->previous_lexical_frame)) {
      if (gc_reference(mm, (void**)&(((GingerObject*)(o))->previous_lexical_frame)))
        reference_frame(mm, (Frame_Narg*)((GingerObject*)(o))->previous_lexical_frame);
    }
    return;
  }

  //
  // Binary Data
  //

  if (GIN_IS_BINARY(o)) {

    stat_binary++;

#ifdef GC_DEBUG
    printf("reference_var: BINARY\n");
#endif
    gc_reference(mm, (void**)&(((GingerBinary*)(o))->value));
    return;
  }

  //
  // Dictionaries
  //
  if (GIN_IS_DICT(o)) {

    stat_dict++;

#ifdef GC_DEBUG
    printf("reference_var: DICT\n");
#endif
    GIN_OBJ x = ((GingerDictionary*)(o))->root;
    if (x && (!GIN_IS_IM(x)) && (gc_reference(mm, &(((GingerDictionary*)(o))->root)))) {
      x = ((GingerDictionary*)(o))->root;
      reference_var(mm, x);
    }
    return;
  }

  //
  // Dictionary Cells
  //

  if (GIN_IS_DICT_CELL(o)) {

    stat_dict_cell++;

#ifdef GC_DEBUG
    printf("reference_var: DICT CELL\n");
#endif
    GIN_OBJ x = ((GingerDictionaryCell*)(o))->left;
    if (x && (!GIN_IS_IM(x)) && (gc_reference(mm, &(((GingerDictionaryCell*)(o))->left)))) {
      x = ((GingerDictionaryCell*)(o))->left;
      reference_var(mm, x);
    }

    x = ((GingerDictionaryCell*)(o))->right;
    if (x && (!GIN_IS_IM(x)) && (gc_reference(mm, &(((GingerDictionaryCell*)(o))->right)))) {
      x = ((GingerDictionaryCell*)(o))->right;
      reference_var(mm, x);
    }

    return;
  }

  //
  // Type Objects
  //

  if (GIN_IS_TYPE(o)) {

    stat_type++;

#ifdef GC_DEBUG
    printf("reference_var: TYPE\n");
#endif
    return;
  }

  //
  // Floats
  //

  if (GIN_IS_FLONUM(o)) {

    stat_float++;

#ifdef GC_DEBUG
    printf("reference_var: FLONUM\n");
#endif
    return;
  }

  //
  // Streams
  //

  if (GIN_IS_STREAM(o)) {

    stat_stream++;

#ifdef GC_DEBUG
    printf("reference_var: STREAM\n");
#endif
    return;
  }

  //
  // String Streams
  //

  if (GIN_IS_STRING_STREAM(o)) {

    stat_string_stream++;

#ifdef GC_DEBUG
    printf("reference_var: STRING STREAM\n");
#endif
    gc_reference(mm, (void**)&(((GingerObject*)(o))->str8_value));
    return;
  }

  //
  // Runtime Types
  //

  stat_other++;


#ifdef GC_DEBUG
  printf("reference_var: RUNTIME TYPE\n");
#endif

  return;
  int type_index = -1;
  int j;
  for (j=0; j<((GingerVector*)(type_table))->length; j++) {
       if (((GingerVector*)(type_table))->value[j] == GIN_NIM_GET_TYPE(o)) {
            type_index = j;
       }
  }
  if (type_index == -1) {
    print_bits32((unsigned long)o);
    print_bits32((unsigned long)(GIN_NIM_GET_TYPE(o)));
    printf ("UNHANDLED TYPE: %d\n", GIN_IM_TO_INT(GIN_NIM_GET_TYPE(o)));
    assert(0);
  }
  return;

}

void reference_frame(GarbageCollector* mm, Frame_Narg* cframe) {
  GIN_OBJ x;
  int i;
  int n;
  #ifdef GC_DEBUG
  printf("reference_frame %d\n", cframe);
  #endif
  n = gc_size(mm, cframe);
  // Invalid Frame
  //  printf("alive? %d\n", gc_active(mm, cframe));
  assert(n != 0);
  n = n - sizeof(Frame);
  // Invalid Frame
  assert(n >= 0);
  assert(n % 4 == 0);
  n /= 4;

  if ((cframe->previous_frame) &&
      (gc_active(mm, (Frame_Narg*)(cframe->previous_frame))) &&
      (gc_reference(mm, (void**)&(cframe->previous_frame)))) {
    reference_frame(mm, (Frame_Narg*)(cframe->previous_frame));
  }

  if ((cframe->next_frame) &&
      (gc_active(mm, (Frame_Narg*)(cframe->next_frame))) &&
      (gc_reference(mm, (void**)&(cframe->next_frame)))) {
    reference_frame(mm, (Frame_Narg*)(cframe->next_frame));
  }

  if ((cframe->previous_lexical_frame) &&
      (gc_active(mm, (Frame_Narg*)(cframe->previous_lexical_frame))) &&
      (gc_reference(mm, (void**)&(cframe->previous_lexical_frame)))) {
    reference_frame(mm, (Frame_Narg*)(cframe->previous_lexical_frame));
  }

  x = cframe->result;
  if (x && (!GIN_IS_IM(x)) && (gc_reference(mm, &(cframe->result)))) {
    reference_var(mm, cframe->result);
  }

  for (i=0; i<n; i++) {
    x = cframe->argn[i];
    //print_bits32(x);
    if (x &&
        (!GIN_IS_IM(x)) &&
        gc_active(mm,  cframe->argn[i]) &&
        (gc_reference(mm, &(cframe->argn[i])))) {
      reference_var(mm, cframe->argn[i]);
    }
  }
}

void collect (GarbageCollector* mm) {
//  printf("GC BEGIN==============================================================\n");

  stat_str8 = 0;
  stat_vector = 0;
  stat_cons = 0;
  stat_function = 0;
  stat_binary = 0;
  stat_dict = 0;
  stat_dict_cell = 0;
  stat_type = 0;
  stat_float = 0;
  stat_stream = 0;
  stat_string_stream = 0;
  stat_other = 0;


  gc_begin_collection(mm);

  // Explore every reachable frame touching everything we can find. It all stems from the current frame.

  gc_reference(mm, (void**)(&frame));
  reference_frame(mm, (Frame_Narg*)frame);

  // Don't need to collect these even though they are also globals because no allocation will happen before it gets put in another var.
  // safe_pair
  // next_func
  // calln_temp

  gc_end_collection(mm);
  gc_system_xfers = 0;
  gc_free_alloc = 0;

/*
  printf ("str8     =%d\n", stat_str8);
  printf ("vector   =%d\n", stat_vector);
  printf ("cons     =%d\n", stat_cons);
  printf ("function =%d\n", stat_function);
  printf ("binary   =%d\n", stat_binary);
  printf ("dict     =%d\n", stat_dict);
  printf ("dict_cell=%d\n", stat_dict_cell);
  printf ("type     =%d\n", stat_type);
  printf ("float    =%d\n", stat_float);
  printf ("stream   =%d\n", stat_stream);
  printf ("string_st=%d\n", stat_string_stream);
  printf ("other    =%d\n", stat_other);

  printf("GC END==============================================================\n");
*/

  return; // Eddie: return so we never reach the following code.
  // TODO - what is this code supposed to do?

  // Now go through and call methods to cleanup garbage
  GIN_OBJ c;
  while (c = gc_get_next_pending_cleanup(mm)) {
    printf("This is not implemented yet.\n");
    assert(0);
    GIN_OBJ d;
    GIN_OBJ safe_allocate;
    GIN_NEW_PAIR(d, c, GIN_NULL);
    long type = (long) GIN_NIM_GET_TYPE(c);
    ginExec(((GingerClassDefinition*)type)->unmake, d);
  }
}
