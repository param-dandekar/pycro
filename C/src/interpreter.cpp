#include <iostream>
#include <string>

#include "interpreter.h"
#include "node.h"
#include "parser.h"

void Interpreter::print_info() {
  std::cout << name << " " << version << std::endl;
}

void Interpreter::run() {
  print_info();
  
  Node root("root");
  Parser p(&root);

  do {
    std::cout << ">>> ";
  } while (p.readline());
  std::cout << std::endl;

  std::cout << root.to_str() << std::endl;
}
