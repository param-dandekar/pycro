#pragma once

#include <string>

#include "type.h"

typedef unsigned char py_bool;

class Boolean : public Type {
  private:
    py_bool value;

  public:
    Boolean(py_bool _value) :
      Type("bool"), value(_value) {}
    std::string to_str() override;
};
