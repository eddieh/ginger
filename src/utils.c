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
#include "ginger.h"

// Adapted from DJB's fmt_ulong in daemontools

GIN_OBJ fmt_ulong(register unsigned long u) {
  register char* s;
  register unsigned int len;
  register unsigned long q;
  GIN_OBJ r;
  len = 1; q = u;
  while (q > 9) { ++len; q /= 10; }
  GIN_ALLOCATE(s, char*, len+1);
  GIN_NEW_EMPTY_STR8(r);
  GIN_STR_VALUE(r) = s;
  GIN_STR_LENGTH(r) = len;
  s[len] = 0;
  s += len;
  do { *--s = '0' + (u % 10); u /= 10; } while(u); /* handles u == 0 */
  return r;
} 

GIN_OBJ fmt_long(register long u) {
  register char* s;
  register unsigned int len; 
  register unsigned long q;
  GIN_OBJ r;
  len = 1; 
  q = u;
  if (u < 0) q *= -1;
  while (q > 9) { ++len; q /= 10; }
  if (u < 0) {
    u *= -1;
    len++;
    GIN_ALLOCATE(s, char*, len+1);
    s[0] = '-';
  } else {
    GIN_ALLOCATE(s, char*, len+1);
  }
  GIN_NEW_EMPTY_STR8(r);
  GIN_STR_VALUE(r) = s; 
  GIN_STR_LENGTH(r) = len; 
  s[len] = 0;
  s += len;
  do { *--s = '0' + (u % 10); u /= 10; } while(u); /* handles u == 0 */
  return r;
}

void print_bits64(unsigned long long q) {
  int i;
  for (i=63; i>=0; i--) {
    unsigned long t = (q << (63-i)) >> 63;
    printf("%d",t);
    if ((i%16)==0) printf(" ");
  }
  printf("\n");
}

void print_bits32(unsigned long q) {
  int i;
  for (i=31; i>=0; i--) {
    unsigned long t = (q << (31-i)) >> 31;
    printf("%d",t);
    if ((i%16)==0) printf(" ");
  }
  printf("\n");
}

GIN_OBJ fmt_double(double d) {

  /*
  unsigned long long q;
  register unsigned int len = 0; 
  memcpy(&q, &d, sizeof(q));

  // The sign
  int s = q >> 63;

  // The exponent (base 2, exponent bias = 1023)
  long e = ((q >> 52) & ((1 << 11) -1)) - 1023;


  // The absolute value of e
  long abs_e = e;
  if (abs_e < 0) abs_e *= -1;

  // The mantissa
  unsigned long long one = 1;
  unsigned long long m = ((q << 12) >> 12) | (one << (63-11));

  // The value is then,
  // -1^s * 2^e * 1.mantissa (binary)

  // Find the position of the most significant digit (msd) and least 
  // significant digit (lsd) in the desired base.

  unsigned long msd;
  ///unsigned long lsd;

  // The exponent (base 10) gives us the msd position
  // log_10(2) = 0.30102999566398114
  // TODO: Better approximation
  msd = 1 + (long)(e*0.30102999566398114);
  ////lsd = 1 + (long)((e-52)*0.30102999566398114);

  ////long digit_count = msd - lsd;

  // add space for sign

  unsigned long long left;
  unsigned long long right;
  int left_len = 0;
  int right_len = 0;

  if (e >= 52) { left = m; right = 0; left_len=52; }
  else if (e <= -52) { left = 0; right = m; right_len=52; }
  else {
    left = m >> (52-e);
    left_len = e+1;
    right = (m << (e+1+12)) >> (e+1+12);
    right_len = (52-e-2);
  }

  if (s) len++;

  // This will loop no more than 16 times.
  while (left >= 10) {
    // Find the lowest digit so far
    unsigned long long d = left - (left/10)*10;
    left /= 10;
  }
  
  // and the right side is trickier..  See also: How to print floating 
  // point numbers by Guy Steele and Jon White.

  */

  // TODO: Complete and total hack follows - well it's not that bad
  // but we will do much better.
  GIN_OBJ r;
  char *s;
  GIN_ALLOCATE(s, char*, 64); // wasting memory..
  sprintf(s, "%g", d);
  GIN_NEW_EMPTY_STR8(r);
  GIN_STR_VALUE(r) = s; 
  GIN_STR_LENGTH(r) = strlen(s); 
  return r;
}


GIN_OBJ fmt_float(float d) {
  GIN_OBJ r;
  char *s;
  GIN_ALLOCATE(s, char*, 64); // wasting memory..
  sprintf(s, "%g", d);
  GIN_NEW_EMPTY_STR8(r);
  GIN_STR_VALUE(r) = s; 
  GIN_STR_LENGTH(r) = strlen(s); 
  return r;
}
