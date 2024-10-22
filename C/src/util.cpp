#include "util.h"

LexerError::LexerError(const char* msg) : message(msg) {}

const char* LexerError::what() {
  return message;
};

const char* SyntaxError::what() {
  return message;
};
