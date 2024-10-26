#include <string>
#include <iostream>

#include "util.h"
#include "color.h"

#include "integer_t.h"
#include "float_t.h"

#include "expression.h"
#include "token.h"

#include "lexer.h"
#include "parser.h"
#include "interpreter.h"

int main (int argc, char *argv[]) {
  Interpreter interpreter;

  interpreter.run();

  return 0;
}
