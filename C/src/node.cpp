#include <string>

#include "node.h"

Node::Node(std::string _name) {
  name = _name;
}

std::string Node::to_str() {
  return name;
}

