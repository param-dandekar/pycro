#include "boolean_t.h"

#include <string>

#include "util.h"

std::string Boolean::to_str() {
  std::string value_str = "";
  if(value) {
    value_str = "True";
  } else {
    value_str = "False";
  }
  return format::style(value_str, CYN, true);
}
