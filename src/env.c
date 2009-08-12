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
#include <sys/stat.h>

GIN_OBJ gin_getenv(GIN_OBJ name, GIN_OBJ default_value) 
{
  GIN_OBJ r;
  char *s = getenv(GIN_STR_VALUE(name));
  if (s != NULL) {
    GIN_NEW_STR8(r, s);
  } else {
    r = default_value;
  }
  return r;
}

GIN_OBJ gin_file_exists (GIN_OBJ filename) {
  struct stat info;
  return GIN_IM_FROM_BOOL(stat(GIN_STR_VALUE(filename), &info) == 0);
}
