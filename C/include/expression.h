#pragma once

#include <string>

#include "node.h"

class Expression : public Node {
  protected:
    std::string type_name;
    
  public:
    Expression(
        std::string _name,
        std::string _type_name
        ) :
      Node(_name),
      type_name(_type_name) {}
    std::string to_str() override;
};
