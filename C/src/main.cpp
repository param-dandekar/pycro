#include <string>
#include <iostream>

#include "util.h"
#include "color.h"

#include "integer_t.h"
#include "float_t.h"

#include "expression.h"
#include "token.h"

int main (int argc, char *argv[]) {
  Integer* int_data = new Integer(42);
  Expression* expr = new Expression(int_data);
  Token* next = new Token(expr);

  Token* head = new Token();

  head->add_token(next);
  next->add_token(new Token(new Expression("PI", new Float(3.14))));

  std::cout << head->to_str() << std::endl;

  return 0;
}
