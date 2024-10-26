#include <string>

#include "util.h"

#include "float_t.h"

std::string Float::to_str() {
  return color(std::to_string(value), COLOR_LIT) + ":" + color(name, COLOR_TYPE); 
}
