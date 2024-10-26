#include "expression.h"

#include <string>

std::string Expression::to_str() {
  if(var_name == "") {
    return type->to_str();
  }
  return var_name + "$" + type->to_str();
}
