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
  bool continue_line = false;
  string buffer;

  while(lexing) {

    cout << ">>> ";
    if(!getline(cin, buffer)) {
      lexing = false;
      break;
    }

    lexer.lexify(buffer, head, continue_line);
  }

  cout << endl;

  if(!head->is_null()) {
    cout << head->to_str() << endl;
  }

  Parser parser(head, root);
}

void Interpreter::print_info() {
  cout << name << " " << version << endl;
}

