#pragma once

#include <string>

#include "object.h"
#include "type.h"

class Expression : public Object {
  private:
    std::string var_name;
    Type* type;

  public:
    Expression() :
      var_name(""), type(NULL) {}
    Expression(Type* _type) :
      var_name(""), type(_type) {}
    Expression(std::string _var_name, Type* _type) :
      var_name(_var_name), type(_type) {}
    ~Expression() {
      delete type;
    }

    std::string to_str() override;
};
