#include <string>

#include "util.h"
#include "expression.h"

Expression::Expression(std::string _name, std::string _type_name) : Node(_name) {
  type_name = _type_name;
}

std::string Expression::to_str() {
  return color(type_name, COLOR_TYPE) + "$" + color(name, COLOR_VAR);
}
