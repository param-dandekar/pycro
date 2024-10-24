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

void read_digit(char c, ParseState state);
void read_char(char c, ParseState state);

//void parse(std::string line);
//void parse_expr(std::string token, Token::Type_e& type);

Token Parser::get_token_list() {
  return head;
}

int Parser::parse_line() {
  int valid = 0;

  state.type = Token::UNKNOWN;

  if(getline(std::cin, buffer)) valid = 1;

  if(buffer.length() > 0) {
    std::cout << "Parsing: " + color(buffer, RED) << std::endl;
    for(int i = 0; char c = buffer[i]; i++) {
      if(state.type == Token::STRING) {
        if(c == state.string_quote) {
          std::cout << state.type << std::endl;
        }
      } else if(is_digit(c)) {
        read_digit(c, state);
      } else if(is_alpha_(c)) {
        read_char(c, state);
      }
    }
  }

  return valid;
}

void read_digit(char c, ParseState state) {
  switch(state.type) {
    case Token::UNKNOWN:
      state.type = Token::INT;
      break;

    case Token::INT:
    case Token::FLOAT:
      state.num_value *= 10;
      state.num_value += ctoi(c);
      break;
    default:
      throw SyntaxError();
  }
}

void read_char(char c, ParseState state) {
  switch(state.type) {
    case Token::UNKNOWN:
      state.type = Token::OTHER;
      state.str_value += c;
      break;

    default:
      throw SyntaxError();
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

/*
void parse(std::string line) {
  Token::Type_e type = Token::UNKNOWN;

  if(line == "")
    return;

  std::cout << "Parsing: " + color(line, RED) << std::endl;

}

void parse_expr(std::string token, Token::Type_e& type) {
  std::string expr = "";

  for(int i = 0; char c = token[i]; i++) {
    if(is_digit(c)) {
      expr += c;
      //std::cout << color(c, COLOR_LIT) << "$int"; 
    } else if(c == '.') {
      type = Token::FLOAT;
      expr += c;
      //std::cout << color(c, COLOR_LIT) << "$float"; 
    } else if(is_operator(c)) {
      expr += c;

      //std::cout << color(c, COLOR_OP); 
    } else {
      throw SyntaxError();
    }
  }
  std::cout << expr << std::endl;
}
*/
