#include "keyword.h"

#include <string>

#include "color.h"
#include "util.h"

std::string Keyword::to_str() {
  return color::s(style) + color::cfg(color, bright) + name + RST;
}
