#pragma once

#include <string>

#include "token.h"
#include "object.h"

/* The parser parses a token list into an abstract syntax tree. */
class Parser {
  private:
    Token* head;
    Object* root;

  public:
    Parser(Token* _head, Object* _root) :
      head(_head), root(_root) {}
};
