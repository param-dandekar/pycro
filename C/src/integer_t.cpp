#include <string>

#include "util.h"

#include "integer_t.h"

std::string Integer::to_str() {
  return color(std::to_string(value), COLOR_LIT) + ":" + color(name, COLOR_TYPE); 
}
