#include "color.h"

#include <string>

namespace color {
  using namespace std;

  string cfg(Color_e color) {
    char color_code[LEN_COLOR_CODE];
    snprintf(color_code, LEN_COLOR_CODE, "\033[3%cm", color);
    return color_code;
  }

  string cfg(Color_e color, bool bright) {
    char color_code[LEN_COLOR_CODE];
    if(bright) {
      snprintf(color_code, LEN_COLOR_CODE, "\033[9%cm", color);
      return color_code;
    }
    return cfg(color);
  }

  string cbg(Color_e color) {
    char color_code[LEN_COLOR_CODE];
    snprintf(color_code, LEN_COLOR_CODE, "\033[4%cm", color);
    return color_code;
  }

  string cbg(Color_e color, bool bright) {
    char color_code[LEN_COLOR_CODE];
    if(bright) {
      snprintf(color_code, LEN_COLOR_CODE, "\033[10%cm", color);
      return color_code;
    }
    return cbg(color);
  }

  string s(Style_e style) {
    if(style == DEF) {
      return "";
    }
    char style_code[LEN_STYLE_CODE];
    snprintf(style_code, LEN_STYLE_CODE, "\033[%cm", style);
    return style_code;
  }
}
