#pragma once

#include <string>

#include "token.h"
#include "object.h"

#include "lexer.h"
#include "parser.h"

class Interpreter {
  private:
    const std::string name = "PyCro";
    const std::string version = "v0.1";

    Token* head;  // Head of token list from lexer
    Object* root; // Root of AST from parser

  public:
    Interpreter() :
      head(NULL), root(NULL) {}
    ~Interpreter() {
      delete head;
      delete root;
    }

    void run();

    void print_info();

    Token* get_tokens();
    Object* get_AST();
};

