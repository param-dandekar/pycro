#include <string>

#include "parse_state.h"

void ParseState::reset() {
  type = UNKNOWN;
  int_value = 0;
  frac_pos = 0;
  frac_value = 0.0;
  str_value = "";
  string_quote = '\0';
}

