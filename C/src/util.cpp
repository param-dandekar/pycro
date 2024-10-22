#include "util.h"

std::string color(std::string str, std::string color) {
  return color+str+RESET;
}

LexerError::LexerError(const char* msg) : message(msg) {}

const char* LexerError::what() {
  return message;
};

const char* SyntaxError::what() {
  return message;
};
