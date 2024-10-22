#include <string>

#include "integer_t.h"

Integer::Integer(py_int _value, std::string _name) : Numeric(_name, "int") {
  value = _value;
}
