#include "token.h"

#include <string>

std::string Token::to_str() {
  std::string data_str = "";
  if(!data) {
    data_str = "(START";
  } else {
    data_str = data->to_str();
  }

  if(next == NULL) {
    return data_str + " -> END)";
  } else {
    return data_str + " -> " + next->to_str();
  }
}

void Token::add_token(Token* _next) {
  next = _next;
}
