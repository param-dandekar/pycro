#include <stdio.h>
#include <iostream>
#include <string>

#include "util.h"
#include "lexer.h"
#include "token.h"
#include "integer_t.h"
#include "float_t.h"
#include "add_op.h"

int main(int argc, char *argv[]) {
  Integer a(0, "a");
  Float b(0.0, "b");
  Add c(&a, &b);
  std::cout << c.to_str() << std::endl;
  return 0;
}
