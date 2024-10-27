#include "lexer.h"

#include <iostream>
#include <string>

#include "util.h"

#include "integer_t.h"
#include "float_t.h"

using namespace std;

bool is_digit(char c) {
  return ('0' <= c && c <= '9');
}

bool is_alpha_(char c) {
  return ('a' <= c && c <= 'z') ||
    ('A' <= c && c <= 'Z') ||
    (c == '_');
}

/* Shift the digit d by n decimal places to the right. */
double right_shift(int d, int n) {
  double f = d;
  while(n--) {
    f /= 10;
  }
  return f;
}


void Lexer::lexify(std::string line) {
  cout << format::style("Lexifying:", RED, true) << " " << line << endl;
  if(!line.length()) {
    cout << "Empty line!" << endl;
    return;
  }

  for(int i = 0; char c = line[i]; i++) {
    /* This stores the return value of the read methods, used for 
     * error handling. */
    ReadResult_e result = ERROR;

    /* If the current token is a string literal, keep reading
     * until the corresponding quote is enncountered. */
    if(state.type == STRING) {
      state.str_value += c;
      result = SUCCESS;
      if(c == state.str_quote) {
        state.str_quote = '\0';
        Lexer::add_token();
      }
    } else {
      if(is_digit(c)) {
        result = Lexer::read_digit(c);
      } else if(is_alpha_(c)) {
        result = Lexer::read_char(c);
      } else if(c == '.') {
        result = Lexer::read_point(i);
      } else if(c == '\'' || c == '\"') {
        state.str_quote = c;
        state.type = STRING;
        state.str_value += c;
//        cerr << format::style("WARNING: ", RED, true) << "nested quotes will result in undefined behaviour!" << endl;
        result = SUCCESS;
      } else {
        Lexer::add_token();
        result = Lexer::read_symbol(c);
      }
    }
    
    if(result == DEFAULT) {
      state.str_value += c;
    } else if(result == ERROR) {
      cerr << state.error_msg << endl;
      break;
    }
  }
  if(state.type == UNKNOWN) {
    cerr << format::style("WARNING: ", RED, true) << "unknown type!" << endl;
  } else {
    Lexer::add_token();
  }
}

void Lexer::add_token() {
  switch(state.type) {
    case INT:
      cout << "int: " << state.int_value << endl;
      break;
    case FLOAT:
      cout << "float: " << state.int_value + state.frac_value << endl;
      break;
    case STRING:
      cout << "str: " << state.str_value << endl;
      break;
    default:
      cout << "unknown: " << state.str_value << endl;
      break;
  }

  state.reset();
}

ReadResult_e Lexer::read_digit(char c) {
  switch(state.type) {
    /* If the current type is unknown and a digit is encountered, it 
     * is assumed to be an integer until a decimal point or an invalid
     * character is encountered. */
    case UNKNOWN:
      state.type = INT; // Assume numbers are integers
                        // until decimal point is encountered

    case INT:
    case FLOAT:
      {
        int d = c - '0';

        if(!state.frac_pos) {
          state.int_value *= 10;
          state.int_value += d;
        } else {
          state.frac_value += right_shift(d, state.frac_pos);
          state.frac_pos++;
        }
      }
      return SUCCESS;

    case IDENTIFIER:
      state.str_value += c;
      return SUCCESS;

    default:
      return DEFAULT;
  }

  state.error_msg = "Reached invalid state.";
  return ERROR;
}

ReadResult_e Lexer::read_char(char c) {
  switch(state.type) {
    case INT:
    case FLOAT:
      state.error_msg = "Invalid numeric literal.";
      return ERROR;
    
    /* Assume that the token is an identifier. Later, check whether
     * it is a keyword. */
    case UNKNOWN:
      state.type = IDENTIFIER;
    case IDENTIFIER:
      state.str_value += c;
      return SUCCESS;

    default:
      return DEFAULT;
  }
  
  state.error_msg = "Reached invalid state.";
  return ERROR;
}

ReadResult_e Lexer::read_point(int i) {
  switch(state.type) {
    /* If the type is unknown or int, it is assumed to be a float. */
    case UNKNOWN:
    case INT:
      state.type = FLOAT;
    case FLOAT:
      /* If a decimal point has already been found, return error. */
      if(state.frac_pos) {
        state.error_msg = "Invalid floating-point number.";
        return ERROR;
      } else {
        state.frac_pos = 1;
      }

    default:
      return DEFAULT;
  }

  state.error_msg = "Reached invalid state.";
  return ERROR;
}

ReadResult_e Lexer::read_symbol(char c) {
  switch(c) {
    case ' ':
      return SUCCESS;

    default:
      break; // Not implemented.
  }
  state.error_msg = "Not implemented.";
  return ERROR;
}
