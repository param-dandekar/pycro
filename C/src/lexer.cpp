#include "lexer.h"

#include <iostream>
#include <string>

#include "util.h"

#include "integer_t.h"
#include "float_t.h"
#include "boolean_t.h"
#include "string_t.h"
#include "null_t.h"
#include "operator.h"
#include "keyword.h"

using namespace std;

bool is_digit(char c) {
  return ('0' <= c && c <= '9');
}

/* This function also accepts _ */
bool is_alpha(char c) {
  return ('a' <= c && c <= 'z') ||
    ('A' <= c && c <= 'Z') ||
    (c == '_');
}

bool is_quote(char c) {
  return (c == '\'') || (c == '\"');
}

bool is_operator(char c) {
  char ops[] = {'+', '-', '*', '-', '&', '|', '^', '~', '=', ':'};

  for(char i : ops) {
    if(c == i) return true;
  }
  return false;
}

bool is_kw_operator(string value) {
  string kw_ops[] = {"in", "is", "and", "or", "not"};

  for(string i : kw_ops) {
    if(value == i) return true;
  }
  return false;
}

bool is_keyword(string value) {
  string kws[] = {"if", "elif", "else", "for", "while",
    "def", "return", "continue", "break", "pass"};

  for(string i : kws) {
    if(value == i) return true;
  }
  return false;
}

/* Shift the digit d by n decimal places to the right. */
double right_shift(int d, int n) {
  double f = d;
  while(n--) {
    f /= 10;
  }
  return f;
}

void Lexer::lexify(std::string line, Token* head, bool& continue_line) {
  continue_line = false;

  if(!line.length()) {
    return;
  }

  for(int i = 0; char c = line[i]; i++) {
    /* This stores the return value of the read methods, used for 
     * error handling. */
    ReadResult_e result = ERROR;

    /* If the current token is a string literal, keep reading
     * until the corresponding quote is encountered. */
    if(continue_line) {
        state.error_msg = "Expected new-line after line continuation.";
        result = ERROR;
    } else if(state.type == STRING) {
      if(c == '\\') {
        if(continue_line) {
          state.str_value += "\\";
          continue_line = false;
        } else {
          continue_line = true;
        }
      } else {
        if(!is_quote(c)) {
          state.str_value += c;
          result = SUCCESS;
        } else {
          if(state.quotes.is_full()) {
            state.error_msg = "Too many nested quotes.";
            result = ERROR;
          } else {
            result = SUCCESS;
            state.str_value += c;
            if(c == state.quotes.peek()) {
              state.quotes.pop();
              if(state.quotes.is_empty()) {
                Lexer::add_token(head);
              }
            } else {
              state.quotes.push(c);
            }
          }
        }
      }
    } else {
      continue_line = false;
      
      if(is_digit(c)) {
        result = Lexer::read_digit(c, head);
      } else if(is_alpha(c)) {
        result = Lexer::read_char(c, head);
      } else if(is_operator(c)) {
        result = Lexer::read_operator(c, head);
      } else if(c == '.') {
        result = Lexer::read_point(i);
      } else if(is_quote(c)) {
        state.type = STRING;
        if(c == state.quotes.peek()) {
          state.quotes.pop();
        } else {
          state.quotes.push(c);
        }
        state.str_value += c;
        result = SUCCESS;
      } else if(c == '\\') {
          continue_line = true;
          Lexer::add_token(head);
          result = SUCCESS;
          if(!state.quotes.is_empty()) {
            state.type = STRING;
          }
      } else {
        Lexer::add_token(head);
        result = Lexer::read_symbol(c);
      }
    }
    
    if(result == DEFAULT) {
      state.str_value += c;
    } else if(result == ERROR) {
      cerr << state.error_msg << endl;
      cerr << "Current string value of state: " << state.str_value
        << format::style(" + ", RED, true) << c << endl;
      break;
    }
  }

  Lexer::add_token(head);
  
  
  if(!continue_line) {
    if(!state.quotes.is_empty()) {
      state.error_msg = "Unterminated string literal.";
      cerr << state.error_msg << endl;
      state.reset();
      state.quotes.clear();
      return;
    }
    Newline* temp = new Newline();
    Token* new_line = new Token(temp);
    head->add_token(new_line);
  } else {
    continue_line = false;
  }

}

void Lexer::add_token(Token* head) {
  if(state.type == UNKNOWN) {
    if(state.str_value == "") return;

    cerr << format::style("WARNING: ", RED, true) <<
      "unknown type for " << state.str_value << "!" << endl;
    return;
  }
  
  Token* new_token;
  Object* data;

  bool set_data = false;

  switch(state.type) {
    case INT:
      data = new Integer(state.int_value);
      set_data = true;
      break;
    case FLOAT:
      data = new Float(state.int_value + state.frac_value);
      set_data = true;
      break;
    case STRING:
      if(!state.quotes.is_empty()) {
        return;
      }
      data = new String(state.str_value); 
      set_data = true;
      break;
    case OPERATOR:
      data = new Operator(state.str_value, false);
      set_data = true;
      break;
    default:
      data = Lexer::identify_token(set_data, state.str_value);
      break;
  }

  if(set_data) {
    new_token = new Token(data);

    if(!head) {
      head = new_token;
    } else {
      head->add_token(new_token);
    }
  } else {
    cerr << "Invalid data!" << endl;
  }
  state.reset();
}

Object* Lexer::identify_token(bool& set_data, string value) {
  // Boolean values
  if(value == "True") {
    set_data = true;
    return new Boolean(1);
  } else if(value == "False") {
    set_data = true;
    return new Boolean(0);
  }
  // Null value
  else if(value == "None") {
    set_data = true;
    return new NoneType();
  } else if(is_kw_operator(value)) {
    set_data = true;
    return new Operator(value, true);
  } else if(is_keyword(value)) {
    set_data = true;
    return new Keyword(value);
  } else {
    set_data = true;
    return new Object(value);
  }
}

ReadResult_e Lexer::read_digit(char c, Token* head) {
  if(state.type == OPERATOR) {
    Lexer::add_token(head);
  }

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

ReadResult_e Lexer::read_char(char c, Token* head) {
  if(state.type == OPERATOR) {
    Lexer::add_token(head);
  }

  switch(state.type) {
    case INT:
    case FLOAT:
      cerr << "val: " << state.str_value
        << format::style(" + ", RED, true) << c << endl;
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

ReadResult_e Lexer::read_operator(char c, Token* head) {
  switch(state.type) {
    case OPERATOR:
      switch(c) {
        case '=':
          state.str_value += c;
          Lexer::add_token(head);
          return SUCCESS;
        case '*':
        case '/':
        case '<':
        case '>':
          if(c == state.str_value[0]) {
            state.str_value += c;
            Lexer::add_token(head);
            return SUCCESS;
          }

        default:
          state.error_msg = "Invalid operator.";
          return ERROR;
      }
      break;

    default:
      Lexer::add_token(head);
      state.type = OPERATOR;
      state.str_value += c;
      return SUCCESS;
  }

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
