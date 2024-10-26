#pragma once

#include <string>

class Node {
  protected:
    std::string name;

  public:
    Node() {}
    Node(std::string _name) :
      name(_name) {}

    virtual std::string to_str();
};
