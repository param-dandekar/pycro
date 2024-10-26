#include <iostream>
#include <string>

#include "util.h"

#include "expression.h"

std::string Expression::to_str() {
  std::string str = "";
  if(var_name != "") {
    str += color(var_name, COLOR_VAR) + "$";
  }
  return str;
}

