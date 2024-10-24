#pragma once

#include <string>

#include "node.h"

class Token {
  private:
    Node data;
    Token* next;

  public:
    enum Type_e {
      UNKNOWN = 0,
      INT,
      FLOAT,
      STRING,
      OTHER // identifier, keyword, or symbol
    };

    Token() {
      next = NULL;
    }
    Token(
        Node _data
        ) : 
      data(_data) {}

    std::string to_str();
    void add_token(Node data);
};

