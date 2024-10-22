#include <string>

#include "variable.h"

Variable::Variable(std::string _name, std::string _var_name) : Node(_name) {
  var_name = _var_name;
}

std::string Variable::to_str() {
  return "{" + name + ": " + var_name + "}";
}
