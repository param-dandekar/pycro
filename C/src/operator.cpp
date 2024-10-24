#include <string>

#include "util.h"
#include "operator.h"

std::string UnaryOperator::to_str() {
  return color(name, COLOR_OP) + "(" + operand->to_str() + ")";
}

std::string BinaryOperator::to_str() {
  return color(name, COLOR_OP) + "(" + l_operand->to_str() + ", " + 
    r_operand->to_str() + ")";
}
