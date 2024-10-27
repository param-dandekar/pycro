#pragma once

#include <string>

#include "type.h"

class NoneType : public Type {
  private:

  public:
    NoneType() :
      Type("NoneType") {}
    std::string to_str() override;
};
