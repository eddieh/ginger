#ifndef PANGO_SUPPORT_H
#define PANGO_SUPPORT_H

#include "ginger.h"

GIN_OBJ gin_pango_get_extents_logical_x(GIN_OBJ layout);
GIN_OBJ gin_pango_get_extents_logical_y(GIN_OBJ layout);
GIN_OBJ gin_pango_get_extents_logical_width(GIN_OBJ layout);
GIN_OBJ gin_pango_get_extents_logical_height(GIN_OBJ layout);

GIN_OBJ gin_pango_layout_index_to_x(GIN_OBJ layout, GIN_OBJ index);
GIN_OBJ gin_pango_layout_index_to_y(GIN_OBJ layout, GIN_OBJ index);

void gin_pango_context_list_families(GIN_OBJ context);

#endif
