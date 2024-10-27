#pragma once

#include <string>

#include "type.h"

typedef long long signed int py_int;

class Integer : public Type {
  private:
    py_int value;

  public:
    Integer(py_int _value) :
      Type("int"), value(_value) {}
    std::string to_str() override;
};
