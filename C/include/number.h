#pragma once

#include <string>

#include "type.h"

template <class T>
class Number : public Type {
  protected:
    T value;

  public:
    Number(
        std::string _name,
        T _value
        ) :
      Type(_name),
      value(_value) {}

    std::string to_str();
};
