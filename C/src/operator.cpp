#include <string>

#include "util.h"
#include "operator.h"

Operator::Operator(std::string _name,
    std::string _symbol) : Node(_name) {
  symbol = _symbol;
}

UnaryOperator::UnaryOperator(std::string _name, std::string _symbol,
    Node* _operand) : Operator(_name, _symbol) {
  operand = _operand;
}

BinaryOperator::BinaryOperator(std::string _name, std::string _symbol,
    Node* _l_operand, Node* _r_operand) : Operator(_name, _symbol) {
  l_operand = _l_operand;
  r_operand = _r_operand;
}

std::string UnaryOperator::to_str() {
  return color(name, COLOR_OP) + "(" + operand->to_str() + ")";
}

std::string BinaryOperator::to_str() {
  return color(name, COLOR_OP) + "(" + l_operand->to_str() + ", " + 
    r_operand->to_str() + ")";
}
