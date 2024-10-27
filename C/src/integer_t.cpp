#include "integer_t.h"

#include <string>

#include "util.h"

std::string Integer::to_str() {
  return format::style(std::to_string(value), BLU, true);
}
