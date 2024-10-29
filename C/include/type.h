#pragma once

#include <string>

#include "object.h"

class Type : public Object {
  public:
    Type(std::string _name) :
      Object(_name) {}
    virtual ~Type() {};

    virtual std::string to_str() = 0;
};
