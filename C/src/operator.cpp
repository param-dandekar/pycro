#include <string>

#include "operator.h"

Operator::Operator(std::string _name, std::string _op_name) : Node(_name) {
  op_name = _op_name;
}
