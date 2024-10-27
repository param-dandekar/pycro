#pragma once

#include <string>

#include "token.h"

enum Type_e {
  UNKNOWN = 0,
  INT,        // integer_t.h
  FLOAT,      // float_t.h
  BOOL,       //
  STRING,     //
  KEYWORD,    //
  IDENTIFIER
};

enum ReadResult_e {
  SUCCESS = 0,
  DEFAULT,
  ERROR
};

/* Stores the current state while lexifying. */
class State {
  public:
    Type_e type;
  
    long long int int_value;
  
    double frac_value;
    int frac_pos; // 0 when the token is not a float

    std::string str_value;
    char str_quote;

    std::string error_msg;

    State() :
      type(UNKNOWN),
      int_value(0), frac_value(0.0), frac_pos(0),
      str_value(""), str_quote('\0'),
      error_msg("Unknown error.") {}

    void reset() {
      type = UNKNOWN;
      int_value = 0;
      frac_value = 0.0;
      frac_pos = 0;
      str_value = "";
      str_quote = '\0';
      error_msg = "Unknown error.";
    }
};

/* The lexer lexifies a raw input string into a list of tokens. */
class Lexer {
  private:
    State state;

    /* The following methods are used to handle the next character while
    * lexifying, depending on the type of character and the current state
    * of the lexer. The return value depends on the action taken:
    *  0: the 'expected' action was taken, e.g. if the character was
    *     a digit, the numeric value in the state was updated.
    *  1: the default behaviour was performed, i.e. the character was
    *     added to the string value in the state.
    *  2: an error occurred.
    *
    * When an error occurs, an error message is stored in the state. */

    ReadResult_e read_digit(char c);
    ReadResult_e read_char(char c);
    ReadResult_e read_point(int i);
    ReadResult_e read_symbol(char c);
    
    // WARNING: This resets the state! 
    void add_token(Token* head);

  public:
    Lexer() :
      state() {}

    void lexify(std::string line, Token* head);
};
