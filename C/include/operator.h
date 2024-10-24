#pragma once

#include <string>

#include "node.h"

class Operator : public Node {
  protected:
    std::string symbol;

  public:
    Operator(
        std::string _name,
        std::string _symbol
        ) :
      Node(_name),
      symbol(_symbol) {}
};

class UnaryOperator : public Operator {
  protected:
    Node* operand;

  public:
    UnaryOperator(
        std::string _name,
        std::string _symbol,
        Node* _operand
        ) :
      Operator(_name, _symbol),
      operand(_operand) {}

    std::string to_str() override;
};

class BinaryOperator : public Operator {
  protected:
    Node* l_operand;
    Node* r_operand;

  public:
    BinaryOperator(
        std::string _name,
        std::string _symbol,
        Node* _l_operand, Node* _r_operand
        ) :
      Operator(_name, _symbol),
      l_operand(_l_operand),
      r_operand(_r_operand) {}

    std::string to_str() override;
};


