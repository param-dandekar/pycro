#include "expression.h"

#include <string>

#include "util.h"

std::string Expression::to_str() {
  if(var_name == "") {
    return type->to_str();
  }
  return format::style(var_name, GRN) + format::style("$", RED) + type->to_str();
}
