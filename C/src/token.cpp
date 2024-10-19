#include <string>

#include "token.h"
#include "util.h"

Token::Token(TokenType _type, const std::string& _name) {
  if(!is_valid_token_name(_name)) {
    throw LexerError("Invalid token name: ", _name);
  } 
  name = _name;
  type = _type;
}

bool Token::is_valid_token_name(const std::string name) {
  return true;
}
