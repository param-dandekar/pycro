#pragma once

#include <string>

class Type {
  protected:
    std::string name;

  public:
    Type(std::string _name) :
      name(_name) {}
    virtual ~Type() {};

    virtual std::string to_str() = 0;
};
