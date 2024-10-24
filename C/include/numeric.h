#pragma once

#include <string>

#include "expression.h"

template <class T>
class Numeric : public Expression {
  private:
    T value;

  public:
    Numeric(
        std::string _name,
        std::string _type_name, 
        T _value
        ) :
      Expression(_name, _type_name),
      value(_value) {}
};
