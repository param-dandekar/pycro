#include <string>

#include "add_op.h"

Add::Add(Node* _l_operand, Node* _r_operand) : 
    BinaryOperator("add", "+", _l_operand, _r_operand) {}
