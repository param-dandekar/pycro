#pragma once

#include <stdexcept>
#include <string>

#define MAXLEN_ERROR 1024

#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"

#define COLOR_TYPE  CYN
#define COLOR_VAR   RED
#define COLOR_LIT   GRN
#define COLOR_OP    YEL

std::string color(char c, std::string color);
std::string color(std::string str, std::string color);

enum Type_e {
  UNKNOWN = 0,
  INT,
  FLOAT,
  STRING,
  OTHER // identifier, keyword, or symbol
};

/* This error is thrown when the lexer encounters something it cannot
 * tokenise. */
class LexerError : public std::exception {
  private:
    const char* message;
  public:
    LexerError() :
      message("Unknown error while lexing.") {}
    LexerError(
        const char* msg
        ) :
      message(msg) {}
    LexerError(
        std::string msg
        ) :
      message(msg.c_str()) {}

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

