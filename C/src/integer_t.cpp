#include "integer_t.h"

#include <string>

std::string Integer::to_str() {
  return std::to_string(value)+"i";
}
