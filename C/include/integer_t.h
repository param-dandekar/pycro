#pragma once

#include <string>

#include "type.h"

typedef signed long long int py_int;

class Integer : public Type {
  protected:
    py_int value;

  public:
    Integer() :
      Type("int") {}
    Integer(py_int _value) :
      Type("int"), 
      value(_value) {}

    std::string to_str();
};
