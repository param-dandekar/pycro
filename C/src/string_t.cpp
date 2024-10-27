#include "string_t.h"

#include <string>

#include "util.h"

std::string String::to_str() {
  return format::style(value, MAG, true);
}
