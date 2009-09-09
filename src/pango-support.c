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

#include <pango/pangocairo.h>
#include <cairo/cairo-pdf.h>

#include "pango-support.h"

GIN_OBJ gin_pango_get_extents_logical_x(GIN_OBJ layout)
{
  return GIN_NULL;
}

GIN_OBJ gin_pango_get_extents_logical_y(GIN_OBJ layout) 
{
  return GIN_NULL;
}

GIN_OBJ gin_pango_get_extents_logical_width(GIN_OBJ layout)
{
  return GIN_NULL;
}

GIN_OBJ gin_pango_get_extents_logical_height(GIN_OBJ layout)
{
  return GIN_NULL;
}

GIN_OBJ gin_pango_layout_index_to_x(GIN_OBJ layout, GIN_OBJ index)
{
  return GIN_NULL;
}

GIN_OBJ gin_pango_layout_index_to_y(GIN_OBJ layout, GIN_OBJ index)
{
     PangoRectangle pr;
     pango_layout_index_to_pos(GIN_NIM_GET_FOREIGN(layout), GIN_IM_TO_INT(index), &pr);
     return GIN_IM_FROM_INT(pr.y);
}

void gin_pango_context_list_families(GIN_OBJ context) 
{
     PangoFontFamily **familes;
     int n;
     pango_context_list_families(GIN_NIM_GET_FOREIGN(context), &familes, &n);
     int i;
     for(i=0; i<n; i++) {
          printf("%s\n", pango_font_family_get_name(familes[i]));
     }
}

