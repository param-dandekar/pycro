#include <stdio.h>
#include <iostream>
#include <string>

/*
#include "util.h"
#include "lexer.h"
#include "token.h"
#include "integer_t.h"
#include "float_t.h"
#include "add_op.h"
*/

#include "interpreter.h"

int main(int argc, char *argv[]) {
  /*
  Integer a(0, "a");
  Float b(0.0, "b");
  Add c(&a, &b);
  Add d(&a, &c);
  std::cout << d.to_str() << std::endl;
  */

  Interpreter interpreter;

  interpreter.run();

  return 0;
}
