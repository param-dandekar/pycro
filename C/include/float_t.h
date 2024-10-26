#pragma once

#include <string>

#include "type.h"

typedef double py_float;

class Float : public Type {
  protected:
    py_float value;

  public:
    Float() :
      Type("float") {}
    Float(py_float _value) :
      Type("float"), 
      value(_value) {}

    std::string to_str();
};
