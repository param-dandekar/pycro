#include <stdio.h>
#include <string>

#include "util.h"
#include "lexer.h"
#include "token.h"

int main(int argc, char *argv[]) {
  try {
    Token token(INTEGER, "int");
  }
  catch (LexerError& e) {
    printf("%s\n", e.what());
  }
  return 0;
}
