#include <iostream>
#include <string>

#include "util.h"

#include "token.h"
#include "node.h"
#include "expression.h"
#include "integer_t.h"
#include "float_t.h"

Token::Token(ParseState state) {
  std::cout << 
    "type: " << state.type << "; " <<
    "int: " << state.int_value << "; " <<
    "frac: " << state.frac_value << "; " <<
    "str: " << state.str_value << "; " <<
    std::endl;
  switch(state.type) {
    case INT: {
        Integer int_data(state.int_value);
        Expression expr("", int_data);
        data = expr;
      } break;/*
    case FLOAT: {
        Float float_data(state.int_value + state.frac_value);
        Expression expr("", &float_data);
        data = &expr;
      } break;*/
    default:
      std::cout << "Not implemented." << std::endl;
  }
}



std::string Token::to_str() {
  if(next == NULL) {
    return "A";
    return data.to_str();
  } else {
    return data.to_str() + "->" + next->to_str();
  }
}
/*
void Token::add_token(Expression data) {
  Token token(data);
  next = &token;
}*/
