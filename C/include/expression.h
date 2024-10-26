#pragma once

#include <string>

#include "node.h"
#include "type.h"

class Expression : public Node {
  protected:
    std::string var_name = "";
    Type type;

  public:
    Expression() : Node(""), type(NULL) {}
    Expression(
        std::string _var_name,
        Type _type
        ) :
      Node(_var_name),
      type(_type) {}

    std::string to_str() override;
};
