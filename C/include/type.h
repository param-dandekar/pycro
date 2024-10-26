
#pragma once

#include <string>
#include <iostream>

class Type {
  protected:
    std::string name;

  public:
    Type() : name("") {}
    Type(std::string _name) :
      name(_name) {}

//    virtual std::string to_str() = 0;
};
