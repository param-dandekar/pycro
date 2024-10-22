#pragma once

#include <string>

#include "numeric.h"

typedef signed long long int py_int;

class Integer : public Numeric {
  private:
    py_int value;
 
  public:
    Integer(py_int _value, std::string _name);
};
