#pragma once

#include <string>

#include "numeric.h"

typedef double py_float;

class Float : public Numeric<py_float> {
  public:
    Float(
        std::string _name,
        py_float _value
        ) :
      Numeric(_name, "float", 0.0) {}
};
