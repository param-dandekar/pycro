#pragma once

#include <string>

#include "util.h"

class ParseState {
  public:
    Type_e type = UNKNOWN;
    long int int_value = 0;
    /* frac_pos indicates the position in the number when reading
     * the fractional part of a float. It is 0 in other cases. */
    int frac_pos = 0;
    double frac_value = 0.0;
    std::string str_value = "";
    char string_quote = '\0';
    void reset();
};
