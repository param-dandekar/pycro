#include <string>
#include <iostream>

#include "integer_t.h"
#include "expression.h"
#include "token.h"

int main (int argc, char *argv[]) {
  Integer* int_data = new Integer(1);
  Expression* expr = new Expression("var", int_data);
  Token* next = new Token(expr);

  Token* head = new Token();

  head->add_token(next);

  std::cout << head->to_str() << std::endl;
  return 0;
}
