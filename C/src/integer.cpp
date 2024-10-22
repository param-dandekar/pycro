#include <string>

#include "integer.h"

Integer::Integer(py_int _value, std::string _name) : Numeric(_name, "int") {
  value = _value;
}
