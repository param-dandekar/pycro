#pragma once

#include <string>

#include "operator.h"

class Add : public BinaryOperator {
  public:
    Add(Node* _l_operand, Node* _r_operand);
};
