#pragma once

#include <string>

#include "object.h"
#include "util.h"

#define DEF_KW_COLOR GRN
#define DEF_KW_BRIGHT false
#define DEF_KW_STYLE DEF

/* Newlines are also considered keywords for the lexer-parser. */
class Keyword : public Object {
  protected:
    Color_e color;
    bool bright;
    Style_e style;

  public:
    Keyword(std::string _name, Color_e _color, bool _bright, Style_e _style) :
      Object(_name), color(_color), bright(_bright), style(_style) {}
    
    Keyword(std::string _name) :
      Keyword(_name, DEF_KW_COLOR, DEF_KW_BRIGHT, DEF_KW_STYLE) {}

    Keyword(std::string _name, Color_e _color) :
      Keyword(_name, _color, DEF_KW_BRIGHT, DEF_KW_STYLE){}

    Keyword(std::string _name, Color_e _color, Style_e _style) :
      Keyword(_name, _color, DEF_KW_BRIGHT, _style){}

    Keyword(std::string _name, Color_e _color, bool _bright) :
      Keyword(_name, _color, _bright, DEF_KW_STYLE){}

    std::string to_str() override;
};

class Newline : public Keyword {
  public:
    Newline() :
      Keyword(";", RED, DEF) {}
};

