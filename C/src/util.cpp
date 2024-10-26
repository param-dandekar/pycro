#include "util.h"

#include <string>

namespace style {
  char* style::c(Color_e color) {
    char* style_string;
    sprintf(style_string, "\033[3%cm", color);
    return (style_string);
  }
}
