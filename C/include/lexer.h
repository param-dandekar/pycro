#pragma once

#include <string>

#include "token.h"

enum Type_e {
  UNKNOWN = 0,
  INT,        // Integer, integer_t.h
  FLOAT,      // Float, float_t.h
  BOOL,       // Boolean
  STRING,     // String
  OPERATOR,   // Operator
  IDENTIFIER
};

/* The lexer lexifies a raw input string into a list of tokens. */
class Lexer {
  private:
    Token* head;

  public:
    Lexer(Token* _head) :
      head(_head) {}

    void lexify(std::string line);
};
