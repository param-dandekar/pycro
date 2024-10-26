#include "util.h"

#include <string>

#include "color.h"

namespace format {
  using namespace std;
  string rst() {
    return RST;
  }

  string style(string str, Color_e _color) {
    return style(str, _color, false);
  }

  string style(string str, Color_e _color, bool _bright) {
    return color::cfg(_color, _bright) + str + RST;
  }

  string style(string str, Style_e _style) {
    return color::s(_style) + str + RST;
  }

  string style(string str, Color_e _color, Style_e _style) {
    return style(str, _color, _style, false);
  }

  string style(string str, Color_e _color, Style_e _style, bool _bright) {
    return color::cfg(_color, _bright) + color::s(_style) + str + RST;
  }
}
