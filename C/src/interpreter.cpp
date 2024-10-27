#include "interpreter.h"

#include <iostream>
#include <string>

#include "util.h"

using namespace std;

void print_info();
void Interpreter::run() {
  print_info();

  Lexer lexer(head);
  bool lexing = true;
  string buffer;

  while(lexing) {
    cout << ">>> ";
    if(!getline(cin, buffer)) {
      lexing = false;
      break;
    }

    lexer.lexify(buffer);
  }

  cout << endl;


  Parser parser(head, root);
}

void Interpreter::print_info() {
  cout << name << " " << version << endl;
}

