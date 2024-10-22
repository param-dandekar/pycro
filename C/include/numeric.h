#pragma once

#include <string>

#include "expression.h"

class Numeric : public Expression {
  public:
    Numeric(std::string _name, std::string _type_name);
};
