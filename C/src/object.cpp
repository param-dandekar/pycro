#include "object.h"

#include <string>

#include "util.h"

#define COLOR WHT
#define STYLE ITA
#define BRIGHT false


std::string Object::to_str() {
  return format::style(name, COLOR, STYLE, BRIGHT);
}
