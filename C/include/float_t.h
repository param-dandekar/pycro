#pragma once

#include <string>

#include "type.h"

typedef double py_float;

class Float : public Type {
  private:
    py_float value;

  public:
    Float(py_float _value) : Type("float"), value(_value) {}
    std::string to_str() override;
};
