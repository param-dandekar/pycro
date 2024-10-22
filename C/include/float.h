#pragma once

#include <string>

#include "numeric.h"

typedef double py_float;

class Float : public Numeric {
  private:
    py_float value;
 
  public:
    Float(py_float _value, std::string _name);
};
