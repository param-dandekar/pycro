#include <string>

#include "token.h"
#include "util.h"

Token::Token(TokenType _type, const char* _name) {
  if(!is_valid_token_name(_name)) {
    char error_msg[MAXLEN_ERROR];
    snprintf(error_msg, MAXLEN_ERROR, "Invalid token name: %s",  _name);
    throw LexerError(error_msg);
  } 
  name = _name;
  type = _type;
}

bool Token::is_valid_token_name(const char* name) {
  return true;
}
