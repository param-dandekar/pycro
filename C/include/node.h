#pragma once

#include <string>

class Node {
  protected:
    std::string name;

  public:
    Node(std::string _name);
    virtual std::string to_str();
};
