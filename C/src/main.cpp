#include <stdio.h>
#include <iostream>
#include <string>

#include "util.h"
#include "lexer.h"
#include "token.h"
#include "integer.h"
#include "float.h"

int main(int argc, char *argv[]) {
  Integer a(0, "a");
  Float b(0.0, "b");
  std::cout << a.to_str() << ", " << b.to_str() << std::endl;
  return 0;
}
