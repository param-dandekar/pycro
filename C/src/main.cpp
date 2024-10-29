#include <string>
#include <iostream>

#include "quotestack.h"
#include "interpreter.h"

int main (int argc, char *argv[]) {
  Interpreter interpreter;
  interpreter.run();

  return 0;
}
