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

GIN_OBJ gin_string_to_float(GIN_OBJ str) {
  GIN_OBJ r;
  double f = atof(GIN_STR_VALUE(str));
  GIN_NEW_FLONUM(r, f);
  return r;
}

// log_e 10
#define M_LN10b 2.30258509299404568402
double exp10 (double arg) {
  return exp(M_LN10b * arg);
}

GIN_OBJ gin_string_to_value(GIN_OBJ obj) {
  int str_len = GIN_STR_LENGTH(obj);
  char* str = GIN_STR_VALUE(obj);
  int i;

  // printf("gin_string_to_value = %s %d\n", str, str_len);

  switch(str_len) {
  case 0:
    return 0;
  case 1:
    if ((str[0] >= 48) && str[0] <= 57) {
      // Number
      return GIN_IM_FROM_INT(str[0]-48);
    } else {
      // Symbol
      // TODO: exclude : , _ and some others
      return GIN_IM_FROM_SYM(str[0]);
    }
  case 4:
    if (strncmp(str, "true", 4) == 0) return GIN_TRUE;
    if (strncmp(str, "null", 4) == 0) return GIN_NULL;
    break;
  case 5:
    if (strncmp(str, "false", 5) == 0) {
      return GIN_FALSE;
    }
    break;
  }

  int u_index = -1;
  for (i=str_len-1; i>=0; i--) {
    if (str[i] == '_') {
      u_index = i;
      break;
    }
  }
  if (u_index >= 0) {
    if (u_index == str_len-1) {
      if (str_len == 2) {
        return GIN_IM_FROM_CHAR8(str[0]);
      }
      switch (str_len-1) {
      case 2:
        if (strncmp(str, "at", 2) == 0) return GIN_IM_FROM_CHAR8('@');
        if (strncmp(str, "cr", 2) == 0) return GIN_IM_FROM_CHAR8('\r');
        if (strncmp(str, "lf", 2) == 0) return GIN_IM_FROM_CHAR8('\f');
      case 3:
        if (strncmp(str, "tab", 3) == 0) return GIN_IM_FROM_CHAR8('\t');
      case 4:
        if (strncmp(str, "null", 4) == 0) return GIN_IM_FROM_CHAR8('\0');
        if (strncmp(str, "pipe", 4) == 0) return GIN_IM_FROM_CHAR8('|');
      case 5:
        if (strncmp(str, "space", 5) == 0) return GIN_IM_FROM_CHAR8(' ');
        if (strncmp(str, "colon", 5) == 0) return GIN_IM_FROM_CHAR8(58);
        if (strncmp(str, "slash", 5) == 0) return GIN_IM_FROM_CHAR8('/');
        if (strncmp(str, "tilde", 5) == 0) return GIN_IM_FROM_CHAR8('~');
      case 6:
        if (strncmp(str, "rparen", 6) == 0) return GIN_IM_FROM_CHAR8(')');
        if (strncmp(str, "lparen", 6) == 0) return GIN_IM_FROM_CHAR8('(');
        if (strncmp(str, "rbrace", 6) == 0) return GIN_IM_FROM_CHAR8('}');
        if (strncmp(str, "lbrace", 6) == 0) return GIN_IM_FROM_CHAR8('{');
      case 7:
        if (strncmp(str, "newline", 7) == 0) return GIN_IM_FROM_CHAR8('\n');
      case 8:
        if (strncmp(str, "lbracket", 8) == 0) return GIN_IM_FROM_CHAR8('[');
        if (strncmp(str, "rbracket", 8) == 0) return GIN_IM_FROM_CHAR8(']');
      case 9:
        if (strncmp(str, "backslash", 8) == 0) return GIN_IM_FROM_CHAR8(92);
      case 10:
        if (strncmp(str, "underscore", 10) == 0) return GIN_IM_FROM_CHAR8('_');
        if (strncmp(str, "semi-colon", 10) == 0) return GIN_IM_FROM_CHAR8(59);
      case 12:
        if (strncmp(str, "single-quote", 12) == 0) return GIN_IM_FROM_CHAR8(39);
        if (strncmp(str, "double-quote", 12) == 0) return GIN_IM_FROM_CHAR8('"');
      }
    }
    if ((u_index == str_len-2) && (str[str_len-1] == 'u')) {
      long a = 0;
      for (i=0; i<str_len-2; i++) {
        a *= 16;
        if ((str[i] >= 48) && str[i] <= 57) {
          a += str[i] - 48;
        } else if ((str[i] >= 65) && str[i] <= 70) {
          a += str[i] - 65 + 10;
        } else if ((str[i] >= 97) && str[i] <= 102) {
          a += str[i] - 48 + 10;
        } else {
          return 0;
        }
        // TODO - does not handle anything beyond ascii
        return GIN_IM_FROM_CHAR8(a);
      }
    } else {
      // It has an underscore, therefore it must be a number.
    }
  }
  if ((u_index == -1) && ((str[0] < 48) || (str[0] > 57))) {
    // It can't be a number because there is no base and it starts with something other than a number
    if (str[0] == '-') {
      if ((str[1] < 48) || (str[1] > 57))
        goto parse_symbol;
    } else {
      goto parse_symbol;
    }
  }

  int base = 0;
  int sign = 1;
  int v1 = 0;
  int v2 = 0;
  int v2_cnt = 0;
  int v3 = 0;
  int k = 0;

  if (u_index == -1) base = 10;
  else {
    for (i=u_index+1; i<str_len; i++) {
      base *= 10;
      if ((str[i] >= 48) && str[i] <= 57) {
        base += str[i] - 48;
      } else {
        return 0;
      }
    }
  }
  if (base > 36) return 0;
  if (base < 2) return 0;
  if (str[0] == '-') {
    sign = -1;
    k++;
  }
  if (str[0] == '+') {
    sign = 1;
    k++;
  }
  if (u_index == -1) u_index = str_len;

  while (k<u_index) {
    if ((str[k] >= 48) && str[k] <= 57) {
      v1 *= base;
      v1 += str[k] - 48;
    } else if ((str[k] >= 65) && str[k] <= 90) {
      v1 *= base;
      v1 += str[i] - 65 + 10;
    } else if ((str[k] >= 97) && str[k] <= 122) {
      v1 *= base;
      v1 += str[i] - 48 + 10;
    } else if (str[k] == '/') {
      k++;
      goto parse_ratio;
      break;
    } else if (str[k] == '.') {
      k++;
      goto parse_decimal;
      break;
    } else if (str[k] == 'E') {
      k++;
      goto parse_exp;
      break;
    } else {
      return 0;
    }
    k++;
  }

  if (k == u_index) {
    v1 *= sign;
    return GIN_IM_FROM_INT(v1);
  }
  assert(0);

 parse_ratio:

  while (k<u_index) {
    v2 *= base;
    if ((str[k] >= 48) && str[k] <= 57) {
      v2 += str[k] - 48;
    } else if ((str[k] >= 65) && str[k] <= 90) {
      v2 += str[i] - 65 + 10;
    } else if ((str[k] >= 97) && str[k] <= 122) {
      v2 += str[i] - 48 + 10;
    } else {
      return 0;
    }
    k++;
  }

  // The ratio is v1 / v2
  // TODO: Implement ratios
  GIN_OBJ r;
  GIN_NEW_FLONUM(r, sign*((float)v1/(float)v2));

 parse_decimal:

  if (base != 10) return 0;

  while (k<u_index) {
    v2 *= base;
    if ((str[k] >= 48) && str[k] <= 57) {
      v2 += str[k] - 48;
    } else if ((str[k] >= 65) && str[k] <= 90) {
      v2 += str[i] - 65 + 10;
    } else if ((str[k] >= 97) && str[k] <= 122) {
      v2 += str[i] - 48 + 10;
    } else if (str[k] == 'E') {
      k++;
      v2_cnt++;
      goto parse_exp;
      break;
    } else {
      return 0;
    }
    k++;
    v2_cnt++;
  }

  GIN_NEW_FLONUM(r, sign*(v1+(float)v2*(1.0/exp10(v2_cnt))));
  return r;

 parse_exp:

  if (base != 10) return 0;

  while (k<u_index) {
    v3 *= base;
    if ((str[k] >= 48) && str[k] <= 57) {
      v3 += str[k] - 48;
    } else if ((str[k] >= 65) && str[k] <= 90) {
      v3 += str[i] - 65 + 10;
    } else if ((str[k] >= 97) && str[k] <= 122) {
      v3 += str[i] - 48 + 10;
    } else {
      return 0;
    }
    k++;
  }

  if (v2_cnt) {
    GIN_NEW_FLONUM(r, sign*((v1+v2*(1.0/exp10(v2_cnt))) * exp10(v3)));
  } else {
    GIN_NEW_FLONUM(r, sign*(v1*exp10(v3)));
  }
  return r;

 parse_symbol:
  // TODO: check if symbol has invalid characters, etc..
  return obj;

}
