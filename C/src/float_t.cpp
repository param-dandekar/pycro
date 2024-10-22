#include <string>

#include "float_t.h"

Float::Float(py_float_t _value, std::string _name) : Numeric(_name, "float") {
  value = _value;
}
