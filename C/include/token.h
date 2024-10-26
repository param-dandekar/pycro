#pragma once

#include <string>

#include "object.h"

/* Tokens form a linked list. */
class Token {
  private:
    Token* next;
    Object* data;

  public:
    Token() :
      next(NULL), data() {}
    Token(Object* _data) :
      next(NULL), data(_data) {}
    ~Token() {
      delete next;
      delete data;
    }

    std::string to_str();
    void add_token(Token* next);
};
