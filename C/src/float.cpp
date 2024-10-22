#include <string>

#include "float.h"

Float::Float(py_float _value, std::string _name) : Numeric(_name, "float") {
  value = _value;
}
