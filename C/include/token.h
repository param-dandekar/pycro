#pragma once

#include <string>

#include "node.h"
#include "expression.h"
#include "parse_state.h"

class Token {
  private:
    Expression data;
    Token* next = NULL;

  public:
    Token() : data() { std::cout << "Making an empty token..." << std::endl; }
    /* A Token should almost always be created
     * directly from a ParseState. */
    Token(ParseState state);

    std::string to_str();
    void add_token(Expression data);
};

