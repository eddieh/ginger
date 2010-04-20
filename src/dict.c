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
#include <assert.h>

GIN_OBJ gin_dict_contains(GIN_OBJ t, GIN_OBJ k) {
  char* k_ptr;
  unsigned int k_len;

  GingerDictionary* tree = (GingerDictionary*)t;
  GIN_OBJ p = tree->root;
  if (p == 0)
    return GIN_FALSE;

  if (GIN_IS_STR8(k)) {
    k_len = GIN_STR_LENGTH(k) + 4;
    k_ptr = GIN_STR_VALUE(k);

    while (!GIN_IS_CONS(p)) {
      GingerDictionaryCell *q = (GingerDictionaryCell*)p;

      unsigned char c = 0;
      if (q->byte < k_len) {
        if (q->byte < 4)
          c = 0;
        else
          c = *(k_ptr+(q->byte-4));
      }
      const int direction = (1+(q->otherbits|c))>>8;
      if (direction == 0)
        p = q->left;
      else
        p = q->right;
    }

  } else {
    k_len = 4;
    if (GIN_IS_IM(k)) {
      k_ptr = (char*)&k;
    } else {
      k_ptr = (char*)&(((GingerObject*)k)->uid);
    }

    while (!GIN_IS_CONS(p)) {
      GingerDictionaryCell *q = (GingerDictionaryCell*)p;

      unsigned char c= 0;
      if (q->byte < k_len) {
        c = *(k_ptr+q->byte);
      }
      const int direction= (1+(q->otherbits|c))>>8;
      if (direction == 0)
        p = q->left;
      else
        p = q->right;
    }

  }

  // Note: p is the leaf cons - it may *not* match the key!!
  GIN_OBJ pk = GIN_NIM_GET_F0(p);
  int pk_len;

  if (GIN_IS_STR8(pk)) {
    pk_len = GIN_STR_LENGTH(pk) + 4;
    if (pk_len != k_len)
      return GIN_FALSE;
    if (strncmp(GIN_STR_VALUE(pk), GIN_STR_VALUE(k), GIN_STR_LENGTH(k)) != 0)
      return GIN_FALSE;
  } else {
    if (pk != k) return GIN_FALSE;
  }

  return p;
}

int gin_dict_insert(GIN_OBJ t, GIN_OBJ kp) {
  char* k_ptr;
  unsigned int k_len;

  GIN_OBJ k = GIN_NIM_GET_F0(kp);
  GingerDictionary* tree = (GingerDictionary*)t;
  GIN_OBJ p = tree->root;

  if (p == 0) {
    // Create new (and only) external node
    tree->root = kp;
    return 0;
  }

  if (GIN_IS_STR8(k)) {
    k_len = GIN_STR_LENGTH(k) + 4;
    k_ptr = GIN_STR_VALUE(k);

    while (!GIN_IS_CONS(p)) {
      GingerDictionaryCell *q = (GingerDictionaryCell*)p;

      unsigned char c= 0;
      if (q->byte < k_len) {
        if (q->byte < 4)
          c = 0;
        else
          c = *(k_ptr+(q->byte-4));
      }
      const int direction= (1+(q->otherbits|c))>>8;
      if (direction == 0)
        p = q->left;
      else
        p = q->right;
    }

  } else {
    k_len = 4;
    if (GIN_IS_IM(k)) {
      k_ptr = (char*)&k;
    } else {
      k_ptr = (char*)&(((GingerObject*)k)->uid);
    }

    while (!GIN_IS_CONS(p)) {
      GingerDictionaryCell *q = (GingerDictionaryCell*)p;

      unsigned char c = 0;
      if (q->byte < k_len) {
        c = *(k_ptr+q->byte);
      }
      const int direction= (1+(q->otherbits|c))>>8;
      if (direction == 0)
        p = q->left;
      else
        p = q->right;
    }

  }

  unsigned long newbyte;
  unsigned long newotherbits;
  GIN_OBJ pk = GIN_NIM_GET_F0(p);
  char* pk_ptr;
  unsigned int pk_len;
  unsigned char c;
  unsigned char d;

  if (GIN_IS_STR8(pk) && GIN_IS_STR8(k)) {
    pk_ptr = GIN_STR_VALUE(pk);
    pk_len = GIN_STR_LENGTH(pk) + 4;

    for (newbyte=0; (newbyte<k_len) && (newbyte<pk_len); ++newbyte) {

      if (newbyte < 4) {
        c = 0;
        d = 0;
      } else {
        c = *(pk_ptr+(newbyte-4));
        d = *(k_ptr+(newbyte-4));
      }
      if (c != d) {
        newotherbits = c^d;
        goto different_byte_found;
      }
    }

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
      if (newbyte < 4)
        c = 0;
      else
        c = k_ptr[newbyte-4];
      newotherbits = c;
      goto different_byte_found;
    }

    // The old key is longer
    if (k_len < pk_len) {
      //    printf("INSERT: old key is longer\n");
      if (newbyte < 4)
        c = 0;
      else
        c = pk_ptr[newbyte-4];
      newotherbits = c;
      goto different_byte_found;
    }

    assert(0);

  } else if (GIN_IS_STR8(pk)) {
    pk_ptr = GIN_STR_VALUE(pk);
    pk_len = GIN_STR_LENGTH(pk) + 4;

    for (newbyte=0; (newbyte<k_len) && (newbyte<pk_len); ++newbyte) {

      if (newbyte < 4) {
        c = 0;
      } else {
        c = *(pk_ptr+(newbyte-4));
      }
      d = k_ptr[newbyte];

      if (c != d) {
        newotherbits = c^d;
        goto different_byte_found;
      }
    }

    // Execution never reaches here.
    assert(0);

  } else if (GIN_IS_STR8(k)) {
    pk_len = 4;
    if (GIN_IS_IM(pk)) {
      pk_ptr = (char*)&pk;
    } else {
      pk_ptr = (char*)&(((GingerObject*)pk)->uid);
    }

    for (newbyte=0; (newbyte<k_len) && (newbyte<pk_len); ++newbyte) {

      c = pk_ptr[newbyte];
      if (newbyte < 4) {
        d = 0;
      } else {
        d = *(k_ptr+(newbyte-4));
      }

      if (c != d) {
        newotherbits = c^d;
        goto different_byte_found;
      }
    }

    // Execution never reaches here.
    assert(0);

  } else {

    pk_len = 4;
    if (GIN_IS_IM(pk)) {
      pk_ptr = (char*)&pk;
    } else {
      pk_ptr = (char*)&(((GingerObject*)pk)->uid);
    }

    for (newbyte=0; (newbyte<k_len) && (newbyte<pk_len); ++newbyte) {
      c = pk_ptr[newbyte];
      d = k_ptr[newbyte];
      if (c != d) {
        newotherbits = c^d;
        goto different_byte_found;
      }
    }

    // It's the same key if the lengths are equal
    if (k_len == pk_len) {
      //    printf("INSERT: lengths equal\n");
      GIN_OBJ z = GIN_NIM_GET_F2(kp);
      GIN_NIM_SET_F2(p, z);
      return 1;
    }

    assert(0);

  }

  printf("This should never be executed.\n");
  assert(0);

 different_byte_found:

  while (newotherbits & (newotherbits-1))
    newotherbits &= newotherbits - 1;

  newotherbits ^= 255;
  unsigned char cc;

  if (GIN_IS_STR8(pk)) {
    if (newbyte < 4) {
      cc = 0;
    } else {
      cc = *(pk_ptr+(newbyte-4));
    }
  } else {
    cc = pk_ptr[newbyte];
  }

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

  if (GIN_IS_STR8(k)) {
    for(;;){
      GIN_OBJ p = *wherep;

      if (GIN_IS_CONS(p)) break;

      GingerDictionaryCell* q = p;
      if (q->byte > newbyte) break;
      if (q->byte == newbyte && q->otherbits > newotherbits) break;

      unsigned char c = 0;
      if (q->byte < k_len) {
        if (q->byte < 4) c = 0;
        else c = k_ptr[q->byte-4];
      }
      const int direction = (1 + (q->otherbits|c)) >> 8;
      if (direction == 0)
        wherep = &(q->left);
      else
        wherep = &(q->right);
    }
  } else {
    for(;;){
      GIN_OBJ p = *wherep;

      if (GIN_IS_CONS(p)) break;

      GingerDictionaryCell* q = p;
      if (q->byte > newbyte) break;
      if (q->byte == newbyte && q->otherbits > newotherbits) break;

      unsigned char c = 0;
      if (q->byte < k_len) {
        c = k_ptr[q->byte];
      }
      const int direction = (1 + (q->otherbits|c)) >> 8;
      if (direction == 0)
        wherep = &(q->left);
      else
        wherep = &(q->right);
    }
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
    GIN_NEW_SAFE_PAIR(r, GIN_NIM_GET_F0(node), r);
    return r;
  }

  if (node == 0)
    return 0;

  GingerDictionaryCell *q = (GingerDictionaryCell*)node;

  gin_dict_keys(q->right, 0);
  gin_dict_keys(q->left, 0);

  return r;
}

GIN_OBJ gin_dict_values (GIN_OBJ node, int init){

  if (init == 1) {
    node = ((GingerDictionary*)node)->root;
    r = GIN_NULL;
  }

  if (GIN_IS_CONS(node)) {
    GIN_OBJ q;
    GIN_NEW_SAFE_PAIR(q, GIN_NIM_GET_F2(node), r);
    r = q;
    return q;
  }

  if (node == 0)
    return 0;

  GingerDictionaryCell *q = (GingerDictionaryCell*)node;

  gin_dict_values(q->right, 0);
  gin_dict_values(q->left, 0);

  return r;
}

