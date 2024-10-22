#pragma once

#include <stdexcept>

#define MAXLEN_ERROR 100

/* This error is thrown when the lexer encounters something it cannot
 * tokenise. */
class LexerError : public std::exception {
  private:
    const char* message;
  public:
    LexerError(const char* msg);
    const char* what(); 
};

/* This error is thrown when the interpreter cannot interpret the code
 * in a valid way. */
class SyntaxError : public std::exception {
  private:
    const char* message = "Syntax error";
  public:
    const char* what(); 
};

