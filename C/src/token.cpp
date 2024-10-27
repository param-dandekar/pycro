#include "token.h"

#include <iostream>
#include <string>

using namespace std;

string Token::to_str() {
  string data_str = "";
  if(!data) {
    data_str = "START";
  } else {
    data_str = data->to_str();
  }

  if(!next) {
    return data_str + " -> END";
  } else {
    return data_str + " -> " + next->to_str();
  }
}

Token* Token::add_token(Token* _next) {
  /*if(!data) {
    cerr << "NULL data!" << endl;
    return NULL;
  }*/
  if(!next) {
    next = _next;
    return _next;
  } 
  return next->add_token(_next);
}

bool Token::is_null() {
  return (!data && !next);
}
