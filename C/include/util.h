#pragma once

#include <string>

#define RST "\033[0m"

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
  DEF = '0',
  BLD,
  DIM,
  ITL,
  UND,
  BLI,
  INV,
  HID,
  STK
};

namespace style {
  std::string c(Color_e color);
};
