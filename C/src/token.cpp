#include "token.h"

#include <string>

using namespace std;

string Token::to_str() {
  string data_str = "";
  if(!data && next) {
    return "{" + next->to_str();
  } else if(data && !next) {
    return data->to_str() + "}";
  } else if(data && next) {
    return data->to_str() + " " + next->to_str();
  } else {
    return "{}";
  }
}

Token* Token::add_token(Token* _next) {
  if(!next) {
    next = _next;
    return _next;
  } 
  return next->add_token(_next);
}

bool Token::is_null() {
  return (!data && !next);
}
