/*
  Copyright 2009 by James Dean Palmer and others.

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

int gin_length(GIN_OBJ s) {
  // Add 4 bytes for the type to each..
  if (GIN_IS_IM(s)) {
    // Treat all immediates as 4 long (plus type)
    return 8;
  } else {
    if (GIN_IS_STR8(s)) {
      return (GIN_STR_LENGTH(s) + 4);
    }
  }
}

static void gin_type_value(GIN_OBJ s, unsigned long* stype, unsigned long* value) {
  if (GIN_IS_IM(s)) {
    if (GIN_IS_IM_SYM(s)) {
      *stype = (unsigned long)(GIN_TYPE_SYMBOL);
      *value = (unsigned long)(GIN_IM_TO_SYM(s));
      return;
    }
    else if (GIN_IS_IM_INT(s)) {
      *stype = (unsigned long)(GIN_TYPE_INTEGER);
      *value = (unsigned long)(GIN_IM_TO_INT(s));
      return;
    }
    else if (GIN_IS_IM_BINARY(s)) {
      *stype = (unsigned long)(GIN_TYPE_BINARY);
      *value = (unsigned long)(GIN_IM_TO_BINARY_RAW(s));
      return;
    } 
    else if (GIN_IS_IM_CHAR8(s)) {
      *stype = (unsigned long)(GIN_TYPE_CHAR);
      *value = (unsigned long)(GIN_IM_TO_CHAR8(s));
      return;
    } 
    else if (GIN_IS_IM_BOOL(s)) {
      *stype = (unsigned long)(GIN_TYPE_BOOL);
      *value = (unsigned long)(GIN_IM_TO_BOOL(s));
      return;
    } 
    else if (GIN_IS_NULL(s)) {
      *stype = (unsigned long)(GIN_TYPE_NULL);
      *value = (unsigned long)s;
      return;
    }
  } else {
    *stype = (unsigned long)(GIN_NIM_GET_TYPE(s));
    *value = 0;
    return;
  }
}

unsigned char gin_element(GIN_OBJ s, int i) {
  unsigned long stype = 0;
  unsigned long value = 0;
  gin_type_value(s, &stype, &value);

  // Handle the type
  if (i < 4) {
    unsigned char c;
    if (i > 0) stype = stype >> 8;
    if (i > 1) stype = stype >> 8;
    if (i > 2) stype = stype >> 8;
    c = stype;
    return c;
  }

  // Handle the value
  if (GIN_IS_IM(s)) {
    i -= 4;
    unsigned char c;
    if (i > 0) value = value >> 8;
    if (i > 1) value = value >> 8;
    if (i > 2) value = value >> 8;
    c = value;
    return c;
  } else {
    if (GIN_IS_STR8(s)) {
      return (unsigned char)(GIN_STR_VALUE(s)[i-4]);
    }
  }
  return 0;  
}

int gin_cmp(GIN_OBJ s, GIN_OBJ t, int len) {
  unsigned long stype = 0;
  unsigned long svalue = 0;
  unsigned long ttype = 0;
  unsigned long tvalue = 0;
  int z = 0;
  unsigned char c, d;
  gin_type_value(s, &stype, &svalue);
  gin_type_value(t, &ttype, &tvalue);

  if (stype != ttype)
    return 1;

  if (GIN_IS_IM(s)) {
    if (svalue != tvalue) return 1;
  } else {
    if (GIN_IS_STR8(s)) {
      for (z=0; z<len-4; z++) {
	c = (unsigned char)(GIN_STR_VALUE(s)[z]);
	d = (unsigned char)(GIN_STR_VALUE(t)[z]);
	if (c != d) return 1;
      }
    }
  }
  return 0;  
}

GIN_OBJ gin_dict_contains(GIN_OBJ t, GIN_OBJ k) {
  GingerDictionary* tree = (GingerDictionary*)t;
  GIN_OBJ p = tree->root;
  const unsigned int k_len = gin_length(k);
  if (p == 0)
    return GIN_FALSE;

  while (!GIN_IS_CONS(p)) {
    GingerDictionaryCell *q = (GingerDictionaryCell*)p;

    unsigned char c= 0;
    if (q->byte < k_len)
      c = gin_element(k, q->byte);
    const int direction= (1+(q->otherbits|c))>>8;
    if (direction == 0)
      p = q->left;
    else
      p = q->right;
  }
  
  // Note: p is the leaf cons - it may *not* match the key!!
  GIN_OBJ pk = GIN_NIM_GET_F0(p);
  int pk_len = gin_length(pk);
  if (pk_len != gin_length(k))
    return GIN_FALSE;

  if (gin_cmp(pk, k, pk_len) != 0)
    return GIN_FALSE;

  return p;
}

int gin_dict_insert(GIN_OBJ t, GIN_OBJ kp) {
  GIN_OBJ k = GIN_NIM_GET_F0(kp);
  GingerDictionary* tree = (GingerDictionary*)t;
  GIN_OBJ p = tree->root;
  const unsigned int k_len = gin_length(k);

  if (p == 0) {
    // Create new (and only) external node
    tree->root = kp;
    return 0;
  }
  
  while (!GIN_IS_CONS(p)) {
    GingerDictionaryCell* q = (GingerDictionaryCell*)p;
 
    unsigned char c = 0;
    if (q->byte < k_len)
      c = gin_element(k, q->byte);
    const int direction= (1+(q->otherbits|c))>>8;
    if (direction == 0)
      p = q->left;
    else
      p = q->right;
  }
  
  unsigned long newbyte;
  unsigned long newotherbits;
  GIN_OBJ pk = GIN_NIM_GET_F0(p);
  const unsigned int pk_len = gin_length(pk);
  
  unsigned char c;
  unsigned char d;
  for (newbyte=0; (newbyte<k_len) && (newbyte<pk_len); ++newbyte) {
    c = gin_element (pk, newbyte);
    d = gin_element (k, newbyte);
    //    printf("c=%d\n", c);
    //    printf("d=%d\n", d);
    if (c != d) {
      newotherbits = c^d;
      //      printf("INSERT: different byte\n");
      goto different_byte_found;
    }
  }
  //  printf("\n");
  
  // It's the same key if the lengths are equal
  if (k_len == pk_len) {
    //    printf("INSERT: lengths equal\n");
    GIN_OBJ z = GIN_NIM_GET_F2(kp);
    GIN_NIM_SET_F2(p, z);
    return 1;
  }

  // The new key is longer
  if (k_len > pk_len) {
    //    printf("INSERT: new key is longer\n");
    c = gin_element(k, newbyte);
    newotherbits = c;
    goto different_byte_found;
  }

  // The old key is longer
  if (k_len < pk_len) {
    //    printf("INSERT: old key is longer\n");
    c = gin_element(pk, newbyte);
    newotherbits = c;
    goto different_byte_found;
  }

  printf("This should never be executed.\n");
  exit(0);
  // return 1;
  
 different_byte_found:
   
  while (newotherbits & (newotherbits-1))
    newotherbits &= newotherbits - 1;

  newotherbits ^= 255;
  unsigned char cc = gin_element(pk, newbyte);
  int newdirection = (1+(newotherbits|cc)) >> 8;
  
  GingerDictionaryCell* newnode;
  GIN_ALLOCATE(newnode, GingerDictionaryCell*, sizeof(GingerDictionaryCell));

  newnode->type_index = GIN_TYPE_DICT_CELL;
  newnode->byte = newbyte;
  newnode->otherbits = newotherbits;
  if ((1-newdirection) == 0)
    newnode->left = kp;
  else
    newnode->right = kp;

  GIN_OBJ* wherep = &tree->root;

  for(;;){
    GIN_OBJ p = *wherep;
    
    if (GIN_IS_CONS(p)) break;

    GingerDictionaryCell* q = p;
    if (q->byte > newbyte) break;
    if (q->byte == newbyte && q->otherbits > newotherbits) break;

    unsigned char c = 0;
    if (q->byte < k_len) c = gin_element(k, q->byte);
    const int direction = (1 + (q->otherbits|c)) >> 8;
    if (direction == 0)
      wherep = &(q->left);
    else
      wherep = &(q->right);
  }
  
  if (newdirection == 0)
    newnode->left = *wherep;
  else
    newnode->right = *wherep;

  *wherep = newnode;
  
  return 2;
}

static GIN_OBJ r;
GIN_OBJ gin_dict_keys (GIN_OBJ node, int init){

  if (init == 1) {
    node = ((GingerDictionary*)node)->root;
    r = GIN_NULL;
  }

  if (GIN_IS_CONS(node)) {
    if (init) {
      GIN_NEW_SAFE_PAIR(r, GIN_NIM_GET_F0(node), r);
      return r;
    } else {
      return GIN_NIM_GET_F0(node);
    }
  }

  if (node == 0)
    return 0;
  
  GingerDictionaryCell *q = (GingerDictionaryCell*)node;

  GIN_OBJ right = gin_dict_keys(q->right, 0);
  GIN_OBJ left = gin_dict_keys(q->left, 0);

  if (right)
    GIN_NEW_SAFE_PAIR(r, right, r);

  if (left)
    GIN_NEW_SAFE_PAIR(r, left, r);

  return r;
}
 
