#pragma once

#include <string>

#include "numeric.h"

class Operator : public Node {
  protected:
    std::string op_name;
    Node* l_operand;
    Node* r_operand;

  public:
    Operator(std::string _name, std::string _op_name);
};
