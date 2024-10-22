#pragma once

#include <string>

enum TokenType {
  INTEGER,
  OPERATOR
};

class Token {
  private:
    TokenType type;
    const char* name;
    bool is_valid_token_name(const char* name);

  public:
    Token(TokenType _type, const char* _name);
};

