#pragma once

#include <string>

#include "node.h"

class Variable : public Node {
  protected:
    std::string var_name;
    
  public:
    Variable(std::string _name, std::string _var_name);
    std::string to_str() override;
};
