#pragma once

#include <string>

#include "variable.h"

class Numeric : public Variable {
  public:
    Numeric(std::string _name, std::string _var_name);
};
