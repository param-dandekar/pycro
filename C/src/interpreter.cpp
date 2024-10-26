#include <iostream>
#include <string>

#include "util.h"

#include "interpreter.h"
#include "node.h"
#include "parser.h"

void Interpreter::print_info() {
  std::cout << name << " " << version << std::endl;
}

void Interpreter::run() {
  print_info();
  
  Node root("root");
  std::cout << "Starting parser..." << std::endl;
  Parser p;
/*  
  bool keep_parsing = true;

  while(keep_parsing) {
    std::cout << ">>> ";
    try {
      keep_parsing = p.parse_line();
    }
    catch (LexerError& e) {
      p.reset_state();
      std::cout << e.what() << std::endl;
    }
  }

  std::cout << std::endl;
*/
//  std::cout << root.to_str() << std::endl;
}
