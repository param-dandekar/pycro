#include "util.h"

std::string color(char c, std::string color) {
  return color+c+RESET;
}

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
