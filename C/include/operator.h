#pragma once

#include <string>

#include "object.h"

class Operator : public Object {
  protected:
    bool is_keyword; // Some operators (and, or, not, in, is) are
                  // keywords instead of having symbols.
  
  public:
    Operator(std::string _symbol, bool _is_keyword) :
      Object(_symbol), is_keyword(_is_keyword) {}

    std::string to_str();
};

