#pragma once

#include <string>

#define RST "\033[0m"

#define LEN_COLOR_CODE 7
#define LEN_STYLE_CODE 5

/* Although this is called color.h, it also covers styling. */

enum ColorType_e {
  FG = '3',
  FG_BRIGHT = '9',
  BG = '4',
  BG_BRIGHT = 'A'
};
enum Color_e {
  BLK = '0',
  RED,
  GRN,
  YEL,
  BLU,
  MAG,
  CYN,
  WHT
};
enum Style_e {
  DEF = '0',  // No style
  BLD,        // Bold
  DIM,        // Dim
  ITA,        // Italic
  UND,        // Underlined
  BLI,        // Blinking
  BLI2,       // Also blinking
  INV,        // Inverted
  HID,        // Hidden
  STK         // Struck-through
};

namespace color {
  /* Color text */
  std::string cfg(Color_e color);
  std::string cfg(Color_e color, bool bright);

  /* Color background */
  std::string cbg(Color_e color);
  std::string cbg(Color_e color, bool bright);

  /* Style text */
  std::string s(Style_e style);
};
