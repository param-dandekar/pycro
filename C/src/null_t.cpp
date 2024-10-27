#include "null_t.h"

#include <string>

#include "util.h"

std::string NoneType::to_str() {
  return format::style("None", RED, true);
}

