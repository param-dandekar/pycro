#include <iostream>
#include <string>

#include "parser.h"

#include "util.h"

#include "token.h"
#include "integer_t.h"
#include "float_t.h"


bool is_digit(char c);
bool is_alpha_(char c); // is c an alphabet or underscore?
bool is_whitespace(char c);
bool is_operator(char c);
bool in(char c, std::string s);
int ctoi(char c); // convert char to int, i.e. '0' to 0 etc.
double right_shift(int d, int n); // returns the digit shifted n places
                                  // to the right (in decimal).

/* If the next character is an integer:
 *  - If the type of the token is unknown, it is set to INT.
 *  - If the token is an INT or a FLOAT, its int_value is updated.
 *  - If the token is of type OTHER, the char is appended to str_value.
 * In all other cases, a generic LexerError is thrown. */
void read_digit(char c, ParseState& state);

/* If the next character is alphabetic or an underscore:
 *  - If the type of the token is unknown, it is set to OTHER.
 *  - If the token is of type OTHER, the char is appended to str_value.
 *  - If the token is an INT or a FLOAT, a LexerError is thrown as this
 *  is not a valid numeric value.
 * In all other cases, a generic LexerError is thrown. */
void read_char(char c, ParseState& state);

void read_point(int i, ParseState& state);

Token Parser::get_token_list() {
  return head;
}

int Parser::parse_line() {
  int valid = 0;

  state.type = UNKNOWN;

  if(getline(std::cin, buffer)) valid = 1;

  if(buffer.length() > 0) {
    std::cout << "Parsing: " + color(buffer, RED) << std::endl;
    for(int i = 0; char c = buffer[i]; i++) {
      if(state.type == STRING) {
        if(c == state.string_quote) {
          std::cout << state.type << std::endl;
        }
      } else if(is_digit(c)) {
        read_digit(c, state);
      } else if(is_alpha_(c)) {
        read_char(c, state);
      } else if(c == '.') {
        read_point(i, state);
      }
    }
    Token token(state);
    //std::cout << token.to_str() << std::endl;
    state.reset();
  }

  return valid;
}

void read_digit(char c, ParseState& state) {
  switch(state.type) {
    case UNKNOWN:
      state.type = INT;

    case INT:
    case FLOAT:
      if(!state.frac_pos) {
        state.int_value *= 10;
        state.int_value += ctoi(c);
      } else {
        state.frac_value += right_shift(ctoi(c), state.frac_pos);
        state.frac_pos++;
      }
      break;

    case OTHER:
      state.str_value += c;
      break;

    default:
      throw LexerError();
  }
}

void read_char(char c, ParseState& state) {
  switch(state.type) {
    case UNKNOWN:
      state.type = OTHER;
    case OTHER:
      state.str_value += c;
      break;

    case INT:
    case FLOAT:
      char error_msg[MAXLEN_ERROR];
      sprintf(error_msg, "Non-numeric char '%c' encountered while reading numeric literal.", c);
      throw LexerError(error_msg);

    default:
      throw LexerError();
  }
}

void read_point(int i, ParseState& state){
  switch(state.type) {
    case UNKNOWN:
    case INT:
      state.type = FLOAT;
    case FLOAT:
      if(state.frac_pos) {
        char error_msg[MAXLEN_ERROR];
        sprintf(error_msg, "A fractional number can only have one decimal point!");
        throw LexerError(error_msg);
      } else {
        state.frac_pos = 1;
      }
      break;
    case OTHER:
      state.str_value += '.';
      break;

    default:
      throw LexerError();
  }
}

bool in(char c, std::string s) {
  for(int i = 0; s[i]; i++) {
    if(s[i] == c) {
      return true;
    }
  }
  return false;
}

bool is_digit(char c) {
  return in(c, "0123456789");
}

bool is_alpha_(char c) {
  return ('A'<=c && c<='Z') || ('a'<=c && c<='z') || (c=='_');
}

bool is_whitespace(char c) {
  return in(c, " \t\n");
}

bool is_operator(char c) {
  return in(c, "+-*/");
}

int ctoi(char c) {
  return c-'0';
}

double right_shift(int d, int n) {
  double res = d;
  while(n--) {
    res /= 10;
  }
  return res;
}

void Parser::reset_state() {
  state.reset();
}
