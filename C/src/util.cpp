#include "util.h"

LexerError::LexerError(const std::string& msg) : message(msg) {}
LexerError::LexerError(const std::string& msg, const std::string& reason) : message(msg+reason) {}

const char* LexerError::what() {
  return message.c_str();
};

const char* SyntaxError::what() {
  return message.c_str();
};
