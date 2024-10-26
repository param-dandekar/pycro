#include "float_t.h"

#include <string>

#include "util.h"
#include "color.h"

std::string Float::to_str() {
  return format::style(std::to_string(value), BLU, DEF, true);
}
