#include "interpreter.h"

#include <iostream>
#include <string>

#include "util.h"

using namespace std;

void print_info();
void Interpreter::run() {
  print_info();

  Lexer lexer;
  bool lexing = true;
  string buffer;

  while(lexing) {
    cout << ">>> ";
    if(!getline(cin, buffer)) {
      lexing = false;
      break;
    }

    lexer.lexify(buffer, head);
  }

  cout << endl;

  if(!head->is_null()) {
    cout << "Tokens: " << head->to_str() << endl;
  }

  Parser parser(head, root);
}

void Interpreter::print_info() {
  cout << name << " " << version << endl;
}

