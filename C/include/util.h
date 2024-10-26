#pragma once

#include <string>

#include "color.h"

namespace format {
  std::string rst();

  std::string style(std::string str, Color_e _color);
  std::string style(std::string str, Color_e _color, bool _bright);
  std::string style(std::string str, Style_e _style);
  std::string style(std::string str, Color_e _color, Style_e _style);
  std::string style(std::string str, Color_e _color, Style_e _style, bool _bright);
};
