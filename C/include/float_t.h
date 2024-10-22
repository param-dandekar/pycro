#pragma once

#include <string>

#include "numeric.h"

typedef double py_float_t;

class Float : public Numeric {
  private:
    py_float_t value;
 
  public:
    Float(py_float_t _value, std::string _name);
};
