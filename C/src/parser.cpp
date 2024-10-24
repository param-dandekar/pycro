#include <iostream>
#include <string>

#include "parser.h"
#include "util.h"
#include "integer_t.h"
#include "float_t.h"

enum TokenType {
  UNKNOWN = 0,
  INT,
  FLOAT,
  STRING
};

bool is_digit(char c);
bool is_whitespace(char c);
bool is_operator(char c);
bool in(char c, std::string s);

void parse_token(std::string token);
void parse_expr(std::string token, TokenType& type);

Token Parser::get_token_list() {
  return head;
}

int Parser::readline() {
  int valid = 0;
  std::string current_token;

  if(getline(std::cin, buffer)) valid = 1;
  
  for(int i = 0; buffer[i]; i++) {
    if(is_whitespace(buffer[i])) {
      parse_token(current_token);
      current_token = "";
      continue;
    } else {
      current_token += buffer[i];
    }
  }

  parse_token(current_token);

  std::cout << head.to_str();

  return valid;
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

bool is_whitespace(char c) {
  return in(c, " \t\n");
}

bool is_operator(char c) {
  return in(c, "+-*/");
}

void parse_token(std::string token) {
  TokenType type = UNKNOWN;

  if(token == "")
    return;

  std::cout << "Parsing: " + color(token, RED) << std::endl;

  if(is_digit(token[0])) {
    type = INT;
    parse_expr(token, type);
  }
}

void parse_expr(std::string token, TokenType& type) {
  std::string expr = "";

  for(int i = 0; char c = token[i]; i++) {
    if(is_digit(c)) {
      expr += c;
      //std::cout << color(c, COLOR_LIT) << "$int"; 
    } else if(c == '.') {
      type = FLOAT;
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

