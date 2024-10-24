#include <string>

#include "token.h"
#include "util.h"

std::string Token::to_str() {
  if(next == NULL) {
    return data.to_str();
  } else {
    return data.to_str() + "->" + next->to_str();
  }
}

void Token::add_token(Node data) {
  next = &Token(data);
}
