#pragma once

#include <string>

#include "numeric.h"

typedef signed long long int py_int;

class Integer : public Numeric<py_int> {
  public:
    Integer(
        std::string _name,
        py_int _value) :
      Numeric(_name, "int", 0) {}
};
