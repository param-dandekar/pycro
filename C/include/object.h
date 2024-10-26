#pragma once

#include <string>

class Object {
  private:
    std::string name;

  public:
    Object() :
      name("") {}
    Object(std::string _name) :
      name(_name) {}
    virtual ~Object() {}

    virtual std::string to_str() = 0;
};
