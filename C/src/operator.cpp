#include "operator.h"

#include <string>

#include "util.h"
#include "color.h"

std::string Operator::to_str() {
  return format::style(name, YEL, is_keyword);
}
