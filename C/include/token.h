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
      if(next) delete next;
      if(data) delete data;
    }

    std::string to_str();
    bool is_null();

    /* Returns a pointer to the last token. */
    Token* add_token(Token* _next);
};
