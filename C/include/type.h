#pragma once

#include <string>

#include "object.h"

class Type : public Object {
  protected:
    std::string name;

  public:
    Type(std::string _name) :
      name(_name) {}
    virtual ~Type() {};

    virtual std::string to_str() = 0;
};
