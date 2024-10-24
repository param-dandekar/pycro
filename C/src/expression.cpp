#include <string>

#include "util.h"
#include "expression.h"

std::string Expression::to_str() {
  return color(type_name, COLOR_TYPE) + "$" + color(name, COLOR_VAR);
}
