/*
  Copyright 2009 by James Dean Palmer and others.
 
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

#ifndef GINGER_H
#define GINGER_H

//#define DEBUG

/// Section 0: Includes

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

/// Section 1: Type and structure definitions
///
/// Here we define all the structures used by Ginger.

/// This is the primary reference used internally by Ginger.  It can hold
/// immediate (chars, fixed ints, symbols, etc.) and non-immediates (a pointer
/// to more complex data structures (foreign objects, floats, dictionaries, 
/// etc.)

#define GIN_OBJ void*

/// Execution frames are allocated per function call.  The specific frame
/// definitions are created by the compiler but these are generic frame
/// definitions that can be used when we don't have more specific frame
/// information available.

typedef struct Frame_t {
  struct Frame_t* next_frame;
  struct Frame_t* previous_frame;
  struct Frame_t* previous_lexical_frame;
  GIN_OBJ return_address;
  GIN_OBJ result;
} Frame;

typedef struct {
  Frame* next_frame;
  Frame* previous_frame;
  Frame* previous_lexical_frame;
  GIN_OBJ return_address;
  GIN_OBJ result;
  // Flexible array member:
  GIN_OBJ argn[];
} Frame_Narg;

typedef struct {
  GIN_OBJ type_index;
  GIN_OBJ left;
  GIN_OBJ right;
  unsigned long byte;
  unsigned char otherbits;
} GingerDictionaryCell;

typedef struct {
  GIN_OBJ type_index;
  GIN_OBJ root;
} GingerDictionary;

/// TODO..

typedef struct GingerClassDefinition_t {
  char* name;
  struct GingerClassDefinition_t* parent;
  GIN_OBJ make;
  GIN_OBJ unmake;
} GingerClassDefinition;

/// Function are first class objects and we have to maintain some metadata 
/// for them.

typedef struct {
  int frame_size;
  void* code;
  char* name;
} GingerFunctionDefinition;

/// This is the primary object type.

typedef struct {
  GIN_OBJ type_index;
  union {
    void*  f0;
    char*  str8_value;
    short* str16_value;
    void*  foreign_value;
    GingerFunctionDefinition*  function;
    FILE* stream;
  };
  union {
    void* f1;
  };
  union {
    void* f2;
    long  str_length;
    Frame* previous_lexical_frame;
  };
} GingerObject;

typedef struct {
  GIN_OBJ type_index;
  double value;
} GingerFlonum;

typedef struct {
  GIN_OBJ type_index;
  long value;
} GingerInteger;

typedef struct {
  GIN_OBJ type_index;
  unsigned long length;
  unsigned long value[];
} GingerBinary;

typedef struct {
  GIN_OBJ type_index;
  long length;
  GIN_OBJ *value;
} GingerVector;

typedef struct {
  GIN_OBJ type_index;
  GIN_OBJ index;  // Always NIM
  //  GIN_OBJ make;
  //  GIN_OBJ unmake;
  GIN_OBJ(*c_make) ();
  void(*c_unmake) (GIN_OBJ);
     
} GingerType;

/// The next datastructures are used for garbage collection.  Ginger uses
/// Slag's GC.  For more info (and licensing) see slag_mm.c.

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
  void* fast_heap_alpha;
  void* fast_heap_beta;

  // not set until collection starts
  void* fast_heap_alpha_end;
  void* fast_heap_beta_end;

  void* alpha_allocation_cursor;
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

} SlagMemoryManager;

/// Section 2: Macro definitions
///

#define GIN_GC_MB 5
#define GIN_GC_INIT mm = slag_mm_new(1024*1024*GIN_GC_MB); slag_mm_set_collection_callback(mm, collect);
#define GIN_ALLOCATE(v, type, size) safe_allocate = (GIN_OBJ)slag_mm_allocate(mm, size); \
v = (type)safe_allocate;

#define GIN_ALLOCATE_WITH_CLEANUP(v, type, size) safe_allocate = (GIN_OBJ)slag_mm_allocate_system(mm, size); \
v = (type)safe_allocate; \
slag_mm_mark_as_requiring_cleanup(mm, v);

/// Calls are split into two macros.  First we allocate the call frame with 
/// CALL_ALLOCATE.  Then you copy any parameters.  Then use CALL.

#define CALL_ALLOCATE(function) \
  ALLOCATE_FRAME___ ## function (frame->next_frame)

#ifdef DEBUG
#define CALLDEBUG(z) for(debug_depth_iterator=0;debug_depth_iterator<debug_depth;debug_depth_iterator++) printf(" "); printf(z); printf("\n"); debug_depth++;
#define ENDDEBUG debug_depth--;
#else
#define CALLDEBUG(z)
#define ENDDEBUG
#endif

#define CALL(previous_lframe,function,seed,result0) \
  frame->next_frame->previous_lexical_frame = previous_lframe; \
  CALLDEBUG(#function); \
  frame->next_frame->previous_frame = frame; \
  frame->next_frame->return_address = &&position_ ## seed ; \
  frame = frame->next_frame; \
  frame->next_frame = 0; \
  goto code_ ## function ; \
position_ ## seed : \
  result0 = frame->next_frame->result; \
  frame->next_frame->previous_frame = 0; \
  frame->next_frame = 0; \
  ENDDEBUG \
  DEALLOCATE_FRAME___ ## function (frame->next_frame)

#define CALLN(previous_lframe,function,seed,result0,varn)	\
  ALLOCATE_FRAME___ ## function (frame->next_frame) \
  frame->next_frame->previous_lexical_frame = previous_lframe; \
  frame->next_frame->previous_frame = frame; \
  frame->next_frame->return_address = &&position_ ## seed ; \
  calln_i = 0; \
  calln_temp = varn; \
  while(1) { \
    ((Frame_Narg *)(frame->next_frame))->argn[calln_i] = (GIN_OBJ)GIN_NIM_GET_F0(calln_temp); \
    calln_i++; \
    if (GIN_NIM_GET_F2(calln_temp) == GIN_NULL) break; \
    calln_temp = GIN_NIM_GET_F2(calln_temp); \
  } \
  frame = frame->next_frame; \
  frame->next_frame = 0; \
  goto code_ ## function ; \
position_ ## seed : \
  result0 = frame->next_frame->result; \
  frame->next_frame->previous_frame = 0; \
  frame->next_frame = 0; \
  DEALLOCATE_FRAME___ ## function (frame->next_frame)

// 1. if it's not a function and has no args, return the value.
// 2. if it's not a function and has args - we need to determine the method to call. then do 3.
// 3. if it is a function, use the signature to properly order the arguments and make the call.
#define CALLNDYNAMIC(function,seed,result0,varn)	\
  if ((varn == GIN_NULL) && !(GIN_IS_FUNCTION(function))) result0 = function; \
  else { \
  if (!GIN_IS_FUNCTION(function)) { \
  } \
  GIN_ALLOCATE(frame->next_frame, Frame*, GIN_NIM_GET_FUNCTION(function)->frame_size); \
  frame->next_frame->previous_lexical_frame = GIN_NIM_GET_PREVIOUS_LEXICAL_FRAME(function); \
  frame->next_frame->previous_frame = frame; \
  frame->next_frame->return_address = &&position_ ## seed ; \
  calln_i = 0; \
  calln_temp = varn; \
  while(1) { \
    if (calln_temp == GIN_NULL) break; \
    ((Frame_Narg *)(frame->next_frame))->argn[calln_i] = (GIN_OBJ)GIN_NIM_GET_F0(calln_temp); \
    calln_i++; \
    if (GIN_NIM_GET_F2(calln_temp) == GIN_NULL) break; \
    calln_temp = GIN_NIM_GET_F2(calln_temp); \
  } \
  next_func = function; \
  frame = frame->next_frame; \
  frame->next_frame = 0; \
  goto *(GIN_NIM_GET_FUNCTION(next_func)->code); \
position_ ## seed : \
  result0 = frame->next_frame->result; \
  frame->next_frame->previous_frame = 0; \
  frame->next_frame = 0; \
}
  //DEALLOCATE_FRAME___ ## function (frame->next_frame)

#define GLOBALS int next_seed = 5000; \
GIN_OBJ calln_temp; \
int calln_i; \
GingerFunctionDefinition gin_function_table[1024]; \
GIN_OBJ next_func; \
GIN_OBJ safe_pair; \
GIN_OBJ safe_allocate; \
SlagMemoryManager* mm; \
int gin_argc; \
char **gin_argv; \
int debug_depth = 0; \
int debug_depth_iterator = 0; \
GIN_OBJ type_table = 0;

#define BEGIN_CODE Frame *frame; \
GIN_OBJ ginExec (GIN_OBJ fn, GIN_OBJ args) { \
  if (fn == 0 ) {

#define MID_CODE return 0; \
  } \
  CALLNDYNAMIC(fn, 4999, frame->result, args); \
  goto end_code_return;

#define END_CODE end_code_return: return frame->result;  \
} \
int main(int argc, char *argv[]) {			\
  gin_argc = argc; \
  gin_argv = argv; \
  GIN_GC_INIT; \
  frame = 0; \
  GIN_ALLOCATE(frame, Frame*, sizeof(Frame));	\
  frame->previous_frame = 0;			\
  frame->result = 0; \
  frame->next_frame = 0;  \
  frame->previous_lexical_frame = 0;		\
  ginExec(0, GIN_NULL); \
  GIN_OBJ main_fn; \
  GIN_NEW_FN(main_fn, &(gin_function_table[0]), 0);	\
  ginExec(main_fn, GIN_NULL); \
  return 0; \
}

#define BEGIN_FUNCTION(function) code_ ## function:

#define END_FUNCTION() frame = frame->previous_frame; \
  goto *(frame->next_frame->return_address);

// GIN_OBJ is defined as a void* but in reality it can hold 
// pointers (non-immediates) and certain useful primitives
// (immediates).  The following describes how the bit string
// works:

// 0000 0000 0000 0000 0000 0000 0000 0000 - Unassigned
// xxxx xxxx xxxx xxxx xxxx xxxx xxxx xxx0 - Pointer to a Ginger Object
// xxxx xxxx xxxx xxxx xxxx xxxx xzzz zz01 - Binary (Untyped Memory) (1-25 bits)
// xxxx xxxx xxxx xxxx xxxx UUU0 1111 1111 - Integer (20 bit)
// xxxx xxxx xxxx xxxx xxxx UU01 1111 1111 - Symbol (20 bit)
// xxxx xxxx xxxx xxxx 0111 1111 1111 1111 - Character (16 bit)
// xxxx xxxx 0111 1111 1111 1111 1111 1111 - Character (8 bit)
// xxxx 0111 1111 1111 1111 1111 1111 1111 - Boolean (1 bit)
// 1111 1111 1111 1111 1111 1111 1111 1111 - NULL

// x = value
// z = secondary value
// U = unused


#define GIN_IM_FLAG 1
#define GIN_IM_FLAG_O 1

#define GIN_IM_FLAG_BINARY 1 // 15
#define GIN_IM_FLAG_BINARY_O 2 // 5
#define GIN_IM_FLAG_BINARY_DO 7

#define GIN_IM_FLAG_INT 255 // 255
#define GIN_IM_FLAG_INT_O 9
#define GIN_IM_FLAG_INT_DO 12

#define GIN_IM_FLAG_SYM 511 // 511
#define GIN_IM_FLAG_SYM_O 10
#define GIN_IM_FLAG_SYM_DO 12

#define GIN_IM_FLAG_CHAR16 32767
#define GIN_IM_FLAG_CHAR16_O 16
#define GIN_IM_FLAG_CHAR8 524287
#define GIN_IM_FLAG_CHAR8_O 24
#define GIN_IM_FLAG_BOOL 134217727
#define GIN_IM_FLAG_BOOL_O 28
#define GIN_IM_FLAG_NULL 4294967295ul

// 2s complement allows us to represent -2^(n-1) through 2^(n-1)-1 where n
// is the number of bits.  So with 20 bits we get..
#define GIN_IM_MAX_INT 524287
#define GIN_IM_MIN_INT -524288

// The unsigned 20 bit gives us 2^(n+1)-1 values (the maximum # of symbols)
#define GIN_IM_MAX_SYMBOL 2097151

// Some helpful constants..

#define GIN_NULL (GIN_OBJ)(GIN_IM_FLAG_NULL)
#define GIN_FALSE (GIN_OBJ)(GIN_IM_FLAG_BOOL)
#define GIN_TRUE (GIN_OBJ)(402653183ul)
#define GIN_IS_TRUE(x) ((GIN_OBJ)(x)==GIN_TRUE)
#define GIN_IS_FALSE(x) ((GIN_OBJ)(x)==GIN_FALSE)
#define GIN_IS_NULL(x) ((GIN_OBJ)(x)==GIN_NULL)

#define CMP_FLAGS(flags, offset, v) ((((unsigned long)(v)) << (32 - offset)) == (flags << (32 - offset)))

// Does a GIN variable contain an immediate object?
#define GIN_IS_IM(x) CMP_FLAGS(GIN_IM_FLAG, GIN_IM_FLAG_O, x)
#define GIN_IS_IM_INT(x) CMP_FLAGS(GIN_IM_FLAG_INT, GIN_IM_FLAG_INT_O, x)
#define GIN_IS_IM_SYM(x) CMP_FLAGS(GIN_IM_FLAG_SYM, GIN_IM_FLAG_SYM_O, x)
#define GIN_IS_IM_BINARY(x) CMP_FLAGS(GIN_IM_FLAG_BINARY, GIN_IM_FLAG_BINARY_O, x)
#define GIN_IS_IM_CHAR16(x) CMP_FLAGS(GIN_IM_FLAG_CHAR16, GIN_IM_FLAG_CHAR16_O, x)
#define GIN_IS_IM_CHAR8(x) CMP_FLAGS(GIN_IM_FLAG_CHAR8, GIN_IM_FLAG_CHAR8_O, x)
#define GIN_IS_IM_BOOL(x) CMP_FLAGS(GIN_IM_FLAG_BOOL, GIN_IM_FLAG_BOOL_O, x)

// Convert from an immediate value to a c value.
#define GIN_IM_TO_INT(m) (((unsigned long)(m)) >> GIN_IM_FLAG_INT_DO)
#define GIN_IM_TO_SIGNED_INT(m) (((long)(m)) >> GIN_IM_FLAG_INT_DO)
#define GIN_IM_TO_SYM(m) (((unsigned long)(m)) >> GIN_IM_FLAG_SYM_DO)
#define GIN_IM_TO_CHAR16(m) (((unsigned long)(m)) >> GIN_IM_FLAG_CHAR16_O)
#define GIN_IM_TO_CHAR8(m) (((unsigned long)(m)) >> GIN_IM_FLAG_CHAR8_O)
#define GIN_IM_TO_BOOL(m) (((unsigned long)(m)) >> GIN_IM_FLAG_BOOL_O)
#define GIN_IM_TO_BINARY(m) (((unsigned long)(m)) >> GIN_IM_FLAG_BINARY_DO)
#define GIN_IM_TO_BINARY_RAW(m) (((unsigned long)(m)) >> GIN_IM_FLAG_BINARY_O)
#define GIN_IM_TO_BINARY_SIGNED(m) ((((long)(m)) << (25 - GIN_IM_TO_BINARY_LENGTH(m))) >> (GIN_IM_FLAG_BINARY_DO + (25 - GIN_IM_TO_BINARY_LENGTH(m))))
#define GIN_IM_TO_BINARY_LENGTH(m) ((((unsigned long)(m)) << (32 - GIN_IM_FLAG_BINARY_DO)) >> (32 - GIN_IM_FLAG_BINARY_DO + GIN_IM_FLAG_BINARY_O))

// Convert from a c value to an immediate value.
#define GIN_IM_FROM_INT(i) ((GIN_OBJ)((((unsigned long)(i)) << GIN_IM_FLAG_INT_DO) | GIN_IM_FLAG_INT))
#define GIN_IM_FROM_SYM(i) ((GIN_OBJ)((((unsigned long)(i)) << GIN_IM_FLAG_SYM_DO) | GIN_IM_FLAG_SYM))
#define GIN_IM_FROM_CHAR16(i) ((GIN_OBJ)((((unsigned long)(i)) << GIN_IM_FLAG_CHAR16_O) | GIN_IM_FLAG_CHAR16))
#define GIN_IM_FROM_CHAR8(i) ((GIN_OBJ)((((unsigned long)(i)) << GIN_IM_FLAG_CHAR8_O) | GIN_IM_FLAG_CHAR8))
#define GIN_IM_FROM_BOOL(i) ((GIN_OBJ)((((unsigned long)(i)) << GIN_IM_FLAG_BOOL_O) | GIN_IM_FLAG_BOOL))
#define GIN_IM_FROM_BINARY(i,len) ((GIN_OBJ)(((((unsigned long)(i)) << GIN_IM_FLAG_BINARY_DO) | GIN_IM_FLAG_BINARY) | ((long)(len) << (GIN_IM_FLAG_BINARY_O))))

#define GIN_TYPE_TYPE GIN_IM_FROM_INT(0)
#define GIN_TYPE_CONS GIN_IM_FROM_INT(1)
#define GIN_TYPE_INTEGER GIN_IM_FROM_INT(2)
#define GIN_TYPE_VECTOR GIN_IM_FROM_INT(3)
#define GIN_TYPE_STR8 GIN_IM_FROM_INT(4)
#define GIN_TYPE_FUNCTION GIN_IM_FROM_INT(5)
#define GIN_TYPE_STREAM GIN_IM_FROM_INT(6)
#define GIN_TYPE_STRING_STREAM GIN_IM_FROM_INT(7)
#define GIN_TYPE_FLONUM GIN_IM_FROM_INT(8)
#define GIN_TYPE_DICT GIN_IM_FROM_INT(9)
#define GIN_TYPE_DICT_CELL GIN_IM_FROM_INT(10)
#define GIN_TYPE_SYMBOL GIN_IM_FROM_INT(11)
#define GIN_TYPE_BINARY GIN_IM_FROM_INT(12)
#define GIN_TYPE_BOOL GIN_IM_FROM_INT(13)
#define GIN_TYPE_NULL GIN_IM_FROM_INT(14)
#define GIN_TYPE_CHAR GIN_IM_FROM_INT(15)
//#define GIN_TYPE_FOREIGN 

/*
#define GIN_TYPE_STR8 1
#define GIN_TYPE_STR16 2
#define GIN_TYPE_FUNCTION 3
#define GIN_TYPE_INT 4
#define GIN_TYPE_FLONUM 5
#define GIN_TYPE_STREAM 6 // file stream
#define GIN_TYPE_STRING_STREAM 7 // string stream
#define GIN_TYPE_VECTOR 8
#define GIN_TYPE_TAG_PAIR 9
#define GIN_TYPE_DICTIONARY 10
#define GIN_TYPE_BCONS 11
#define GIN_TYPE_BINARY 100 // 100 .. ? is reserved
*/

// What kind of object does a GIN object contain?
// #define GIN_IS_INT(x) (GIN_IS_IM_INT(x)||GIN_IS_FIXNUM(x))
#define GIN_IS_INT(x) (GIN_IS_IM_INT(x))
#define GIN_IS_STR8(x) ((!GIN_IS_IM(x))&&(((GingerObject*)x)->type_index==GIN_TYPE_STR8))
#define GIN_IS_FUNCTION(x) ((!GIN_IS_IM(x))&&(((GingerObject*)x)->type_index==GIN_TYPE_FUNCTION))

#define GIN_IS_SYM(x) GIN_IS_IM_SYM(x)
#define GIN_IS_CLASSID(x) GIN_IS_IM_CLASSID(x)
#define GIN_IS_CHAR16(x) GIN_IS_IM_CHAR16(x)
#define GIN_IS_CHAR8(x) GIN_IS_IM_CHAR8(x)
#define GIN_IS_CHAR(x) (GIN_IS_IM_CHAR8(x)||GIN_IS_IM_CHAR16(x))
#define GIN_IS_BOOL(x) GIN_IS_IM_BOOL(x)
#define GIN_IS_STR16(x) ((!GIN_IS_IM(x))&&(((GingerObject*)x)->type_index==GIN_TYPE_STR16))
//#define GIN_IS_STR(x) (GIN_IS_STR8(x)||GIN_IS_STR16(x))
#define GIN_IS_STR(x) (GIN_IS_STR8(x))
#define GIN_IS_CONS(x) ((!GIN_IS_IM(x))&&(((GingerObject*)x)->type_index==GIN_TYPE_CONS))
#define GIN_IS_BCONS(x) ((!GIN_IS_IM(x))&&(((GingerObject*)x)->type_index==GIN_TYPE_BCONS))
#define GIN_IS_TYPE_PAIR(x) ((!GIN_IS_IM(x))&&(((GingerObject*)x)->type_index==GIN_TYPE_TAG_PAIR))
#define GIN_IS_FIXNUM(x) ((!GIN_IS_IM(x))&&(((GingerObject*)x)->type_index==GIN_TYPE_INT))
#define GIN_IS_FLONUM(x) ((!GIN_IS_IM(x))&&(((GingerObject*)x)->type_index==GIN_TYPE_FLONUM))
#define GIN_IS_STREAM(x) ((!GIN_IS_IM(x))&&(((GingerObject*)x)->type_index==GIN_TYPE_STREAM))
#define GIN_IS_STRING_STREAM(x) ((!GIN_IS_IM(x))&&(((GingerObject*)x)->type_index==GIN_TYPE_STRING_STREAM))
#define GIN_IS_VECTOR(x) ((!GIN_IS_IM(x))&&(((GingerObject*)x)->type_index==GIN_TYPE_VECTOR))
#define GIN_IS_BINARY(x) ((!GIN_IS_IM(x))&&(((GingerObject*)x)->type_index==GIN_TYPE_BINARY))
#define GIN_IS_DICT(x) ((!GIN_IS_IM(x))&&(((GingerObject*)x)->type_index==GIN_TYPE_DICT))
#define GIN_IS_DICT_CELL(x) ((!GIN_IS_IM(x))&&(((GingerObject*)x)->type_index==GIN_TYPE_DICT_CELL))
#define GIN_IS_TYPE(x) ((!GIN_IS_IM(x))&&(((GingerObject*)x)->type_index==GIN_TYPE_TYPE))

// Create a ginger object..
#define GIN_NEW_CONS(v,a,b,c) GIN_ALLOCATE(v, void*, sizeof(GingerObject)); \
((GingerObject*)v)->type_index = GIN_TYPE_CONS; \
 GIN_NIM_SET_F0(v,a); \
 GIN_NIM_SET_F1(v,b); \
 GIN_NIM_SET_F2(v,c);
#define GIN_NEW_BCONS(v,a,b,c) GIN_ALLOCATE(v, void*, sizeof(GingerObject)); \
((GingerObject*)v)->type_index = GIN_TYPE_BCONS; \
 GIN_NIM_SET_F0(v,a); \
 GIN_NIM_SET_F1(v,b); \
 GIN_NIM_SET_F2(v,c);
#define GIN_NEW_PAIR(v,a,b) GIN_ALLOCATE(v, void*, sizeof(GingerObject)); \
((GingerObject*)v)->type_index = GIN_TYPE_CONS; \
 GIN_NIM_SET_F0(v,a); \
 GIN_NIM_SET_F1(v,GIN_NULL); \
 GIN_NIM_SET_F2(v,b);
#define GIN_NEW_SAFE_PAIR(v,a,b) GIN_ALLOCATE(safe_pair, void*, sizeof(GingerObject)); \
((GingerObject*)safe_pair)->type_index = GIN_TYPE_CONS; \
 GIN_NIM_SET_F0(safe_pair,a); \
 GIN_NIM_SET_F1(safe_pair,GIN_NULL); \
 GIN_NIM_SET_F2(safe_pair,b); \
 v = safe_pair;
#define GIN_NEW_TAG_PAIR(v,a,b) GIN_ALLOCATE(safe_pair, void*, sizeof(GingerObject)); \
((GingerObject*)safe_pair)->type_index = GIN_TYPE_TAG_PAIR; \
 GIN_NIM_SET_F0(safe_pair,a); \
 GIN_NIM_SET_F1(safe_pair,GIN_NULL); \
 GIN_NIM_SET_F2(safe_pair,b); \
 v = safe_pair;
#define GIN_NEW_FIXNUM(v,a) v=GIN_IM_FROM_INT(a);
/* #define GIN_NEW_INTEGER_FROM_INT(v, a) GIN_ALLOCATE_WITH_CLEANUP(v, GingerInteger*, sizeof(GingerInteger)); \ */
/* ((GingerInteger*)v)->type_index = GIN_TYPE_INT;				\ */
/* mpz_init_set_si(((GingerInteger*)v)->value, a); */
/* #define GIN_NEW_INTEGER_FROM_STR(v, a) GIN_ALLOCATE_WITH_CLEANUP(v, GingerInteger*, sizeof(GingerInteger)); \ */
/* ((GingerInteger*)v)->type_index = GIN_TYPE_INT;				\ */
/* printf("herez!!?\n\n");						\ */
/* mpz_init ((((GingerInteger*)v)->value));  */
/* mpz_init_set_str((((GingerInteger*)v)->value), a, 10); */
#define GIN_NEW_FN(v,a,frame) GIN_ALLOCATE(v, void*, sizeof(GingerObject)); \
((GingerObject*)v)->type_index = GIN_TYPE_FUNCTION; \
((GingerObject*)v)->function = a; \
((GingerObject*)v)->previous_lexical_frame = frame;
#define GIN_NEW_CHAR8(v,a) v=GIN_IM_FROM_CHAR8(a);
#define GIN_NEW_CHAR16(v,a) v=GIN_IM_FROM_CHAR16(a);
#define GIN_NEW_STR8(v,a) GIN_ALLOCATE(v, void*, sizeof(GingerObject)); \
((GingerObject*)v)->type_index = GIN_TYPE_STR8; \
((GingerObject*)v)->str_length = strlen(a); \
GIN_ALLOCATE(((GingerObject*)v)->str8_value, char*, ((GingerObject*)v)->str_length + 1); \
memcpy(((GingerObject*)v)->str8_value, a, ((GingerObject*)v)->str_length); \
((GingerObject*)v)->str8_value[((GingerObject*)v)->str_length] = 0;
#define GIN_NEW_EMPTY_STR8(v) GIN_ALLOCATE(v, void*, sizeof(GingerObject)); \
((GingerObject*)v)->type_index = GIN_TYPE_STR8; \
((GingerObject*)v)->str_length = 0;
#define GIN_NEW_STR16(v,a) GIN_ALLOCATE(v, void*, sizeof(GingerObject));	\
((GingerObject*)v)->type_index = GIN_TYPE_STR16; \
((GingerObject*)v)->str16_value = a;
#define GIN_NEW_SYM(v,a) v=GIN_IM_FROM_SYM(a);
#define GIN_NEW_BOOL(v,a) v=GIN_IM_FROM_BOOL(a);
#define GIN_NEW_OBJ(v,a) v=a;
#define GIN_NEW_FLONUM(v,a) GIN_ALLOCATE(v, void*, sizeof(GingerFlonum));	\
((GingerFlonum*)v)->type_index = GIN_TYPE_FLONUM; \
((GingerFlonum*)v)->value = a;
#define GIN_NEW_NIM(v) GIN_ALLOCATE(v, void*, sizeof(GingerObject));

#define GIN_NEW_NIM_WITH_CLEANUP(v) GIN_ALLOCATE_WITH_CLEANUP(v, void*, sizeof(GingerObject));

#define GIN_NEW_STREAM(v,s,m) GIN_ALLOCATE(v, void*, sizeof(GingerObject)); \
((GingerObject*)v)->type_index = GIN_TYPE_STREAM; \
((GingerObject*)v)->stream = s; \
GIN_NIM_SET_STREAM_MODE(v,m);

#define GIN_INPUT_STREAM_MODE 1
#define GIN_OUTPUT_STREAM_MODE 0
#define GIN_NIM_SET_STREAM_MODE(v,m) ((GingerObject*)v)->str_length = \
(long)((((GingerObject*)v)->str_length) | (long)m);
#define GIN_IS_INPUT_STREAM(v) ((GIN_IS_STREAM(v)||GIN_IS_STRING_STREAM(v))&&(((((GingerObject*)v)->str_length) & 0x00000001)==GIN_INPUT_STREAM_MODE))
#define GIN_IS_OUTPUT_STREAM(v) ((GIN_IS_STREAM(v)||GIN_IS_STRING_STREAM(v))&&((((((GingerObject*)v)->str_length)) & 0x00000001)==GIN_OUTPUT_STREAM_MODE))

// TODO - rename get type index
#define GIN_NIM_GET_TYPE(v) ((GingerObject*)v)->type_index
#define GIN_NIM_GET_TYPE_OBJECT(v) ((GingerVector*)type_table)->value[GIN_IM_TO_INT(((GingerObject*)v)->type_index)]

/*
  A string stream has [length : position : mode] encoded in str_length where:
  length   31:17
  position 16:2
  mode     1:0
 */
#define GIN_NIM_GET_STRING_STREAM_LENGTH(v) (long)(((long)((GingerObject*)v)->str_length) >> 17)
#define GIN_NIM_SET_STRING_STREAM_LENGTH(v,l) ((GingerObject*)v)->str_length = \
    (long)((((GingerObject*)v)->str_length) & 0x0001FFFF) | ((long)l << 17);

#define GIN_NIM_GET_STRING_STREAM_POSITION(v) (long)((((long)((GingerObject*)v)->str_length) & 0x0001FFFC) >> 2)
#define GIN_NIM_SET_STRING_STREAM_POSITION(v,p) ((GingerObject*)v)->str_length = \
    (long)((((GingerObject*)v)->str_length) & 0xFFFE0003) | ((long)p << 2);

#define GIN_NEW_STRING_STREAM(v,s,m) GIN_ALLOCATE(v, void*, sizeof(GingerObject)); \
((GingerObject*)v)->type_index = GIN_TYPE_STRING_STREAM; \
GIN_NIM_SET_STRING_STREAM_LENGTH(v,strlen(s)); \
GIN_NIM_SET_STRING_STREAM_POSITION(v,0); \
GIN_ALLOCATE(((GingerObject*)v)->str8_value, char*, strlen(s)+1);	\
GIN_NIM_SET_STREAM_MODE(v,m); \
memcpy(((GingerObject*)v)->str8_value, s, strlen(s)+1);

#define GIN_NEW_EMPTY_STRING_STREAM(v,m) GIN_ALLOCATE(v, void*, sizeof(GingerObject)); \
((GingerObject*)v)->type_index = GIN_TYPE_STRING_STREAM; \
((GingerObject*)v)->str_length = 0; \
GIN_NIM_SET_STREAM_MODE(v,m);

// GL Images Objects
// foreign_value =>  data
// cdr(bit 31-16) => width
// cdr(bit 15-00) => height

#define GIN_TYPE_GL_RGB_IMAGE 2000
#define GIN_TYPE_GL_RGBA_IMAGE 2001

#define GIN_NEW_GL_RGB_IMAGE(v) \
GIN_ALLOCATE(v, void*, sizeof(GingerObject)); \
((GingerObject*)v)->type_index = GIN_TYPE_GL_RGB_IMAGE;

#define GIN_NEW_GL_RGBA_IMAGE(v) \
GIN_ALLOCATE(v, void*, sizeof(GingerObject)); \
((GingerObject*)v)->type_index = GIN_TYPE_GL_RGBA_IMAGE;

#define GIN_NIM_SET_GL_RGB_DATA(v,data) ((GingerObject*)v)->foreign_value = data;
#define GIN_NIM_GET_GL_RGB_DATA(v) ((GingerObject*)v)->foreign_value

#define GIN_NIM_SET_GL_RGB_IMAGE_WIDTH(v,w) ((GingerObject*)v)->cdr_value = \
(GIN_OBJ) ((((int)((GingerObject*)v)->cdr_value) & 0x0000FFFF) | ((int)w << 16));
#define GIN_NIM_GET_GL_RGB_IMAGE_WIDTH(v) (int)(((int)((GingerObject*)v)->cdr_value) >> 16)

#define GIN_NIM_SET_GL_RGB_IMAGE_HEIGHT(v,h) ((GingerObject*)v)->cdr_value = \
(GIN_OBJ)((((int)((GingerObject*)v)->cdr_value) & 0xFFFF0000) | (int)h);
#define GIN_NIM_GET_GL_RGB_IMAGE_HEIGHT(v) (int)(((int)((GingerObject*)v)->cdr_value) & 0x0000FFFF)

#define GIN_TYPE_C_VECTOR 3000
#define GIN_NEW_C_VECTOR(v) \
GIN_ALLOCATE(v, void*, sizeof(GingerObject)); \
((GingerObject*)v)->type_index = GIN_TYPE_C_VECTOR;

#define GIN_NIM_SET_F0(v,a) ((GingerObject*)v)->f0 = a;
#define GIN_NIM_SET_F1(v,a) ((GingerObject*)v)->f1 = a;
#define GIN_NIM_SET_F2(v,a) ((GingerObject*)v)->f2 = a;

#define GIN_NIM_GET_F0(v) ((GingerObject*)v)->f0
#define GIN_NIM_GET_F1(v) ((GingerObject*)v)->f1
#define GIN_NIM_GET_F2(v) ((GingerObject*)v)->f2

#define GIN_HAS_NEXT(next) (GIN_NIM_GET_F2(next)) != GIN_NULL)

#define GIN_STR_LENGTH(x) (((GingerObject*)x)->str_length)
#define GIN_STR_VALUE(x) (((GingerObject*)x)->str8_value)

#define GIN_NIM_SET_FOREIGN(v,a) ((GingerObject*)v)->foreign_value = a;
#define GIN_NIM_GET_FOREIGN(v) ((GingerObject*)v)->foreign_value

#define GIN_NIM_SET_FUNCTION(v,a) ((GingerObject*)v)->function = a;
#define GIN_NIM_GET_FUNCTION(v) ((GingerObject*)v)->function

#define GIN_NIM_SET_PREVIOUS_LEXICAL_FRAME(v,a) ((GingerObject*)v)->previous_lexical_frame = a;
#define GIN_NIM_GET_PREVIOUS_LEXICAL_FRAME(v) ((GingerObject*)v)->previous_lexical_frame

#define GIN_NIM_SET_FLONUM(v,a) ((GingerFlonum*)v)->value = a;
//#define GIN_NIM_GET_FLONUM(v) (double)((GIN_IS_FLONUM(v)) ? (((GingerFlonum*)v)->value) : (mpz_get_d(GIN_NIM_GET_INTEGER(v))))
#define GIN_NIM_GET_FLONUM(v) (double)((GIN_IS_FLONUM(v)) ? (((GingerFlonum*)v)->value) : (GIN_IM_TO_INT(v)))

#define GIN_NIM_SET_INTEGER(v,a) ((GingerInteger*)v)->value = a;
#define GIN_NIM_GET_INTEGER(v) ((GingerInteger*)v)->value

//#define GIN_NIM_GET_FIXNUM_CSTR(v) mpz_get_str(NULL, 10, GIN_NIM_GET_INTEGER(v))

#define GIN_NIM_SET_STREAM(v,stream) ((GingerObject*)v)->stream = stream;
#define GIN_NIM_GET_STREAM(v) ((GingerObject*)v)->stream

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

//
// Section 3: Function prototypes
//

extern SlagMemoryManager* slag_mm_new (int page_size);
extern void slag_mm_set_collection_callback(SlagMemoryManager*mm, void(*callback)(SlagMemoryManager*));
extern void slag_mm_shut_down(SlagMemoryManager* mm);
extern void* slag_mm_allocate(SlagMemoryManager* mm, int size);
extern void* slag_mm_allocate_system(SlagMemoryManager* mm, int size);
extern void* slag_mm_allocate_persistent(SlagMemoryManager* mm, int size);
extern void slag_mm_begin_collection(SlagMemoryManager* mm);
extern void slag_mm_end_collection(SlagMemoryManager* mm);
extern short slag_mm_reference(SlagMemoryManager* mm, void** ptr);
extern unsigned long slag_mm_size(SlagMemoryManager *mm, void *m);
extern void slag_mm_report(SlagMemoryManager *m);
extern void slag_mm_mark_as_requiring_cleanup(SlagMemoryManager *mm, void *m);
extern void* slag_mm_get_next_pending_cleanup(SlagMemoryManager *mm);
extern void slag_analyze(SlagMemoryManager* mm, void* addr);

extern GIN_OBJ ginExec (GIN_OBJ fn, GIN_OBJ args);
extern void GIN_display(GIN_OBJ x, GIN_OBJ out, int was_not_cdr);
extern double *GIN_list_to_double_vector(GIN_OBJ list);
extern float *GIN_list_to_float_vector(GIN_OBJ list);
extern int *GIN_list_to_int_vector(GIN_OBJ list);
extern char *GIN_list_to_char_vector(GIN_OBJ list);
extern void *GIN_list_to_void_vector(GIN_OBJ list);
extern void GIN_int_vector_fill_list(GIN_OBJ vector, GIN_OBJ list);
extern GIN_OBJ fmt_ulong(unsigned long u);
extern GIN_OBJ fmt_long(long u);
extern GIN_OBJ fmt_double(double);
extern GIN_OBJ fmt_float(float);
void print_bits32(unsigned long q);
void print_bits64(unsigned long long q);
extern int gin_dict_insert(GIN_OBJ t, GIN_OBJ kp);
extern GIN_OBJ gin_dict_contains(GIN_OBJ t, GIN_OBJ k);
extern GIN_OBJ gin_dict_keys(GIN_OBJ, int);

extern void collect (SlagMemoryManager* mm);

extern GIN_OBJ gin_getenv(GIN_OBJ name, GIN_OBJ default_value);
extern GIN_OBJ gin_file_exists(GIN_OBJ filename);

/// Section 4: Global variables
///

extern GIN_OBJ safe_allocate;
extern GIN_OBJ next_func;
extern GIN_OBJ safe_pair;
extern SlagMemoryManager* mm;
extern Frame *frame;
extern GingerClassDefinition cdef[];
extern int cdef_count;
extern int gin_argc;
extern char** gin_argv;
extern GIN_OBJ type_table;

#endif /* GINGER_H */
