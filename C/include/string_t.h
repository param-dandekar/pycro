#pragma once

#include <string>

#include "type.h"

typedef std::string py_str;

class String : public Type {
  private:
    py_str value;

  public:
    String(py_str _value) :
      Type("str"), value(_value) {}
    std::string to_str() override;
};
