#include <string>

#include "node.h"
#include "token.h"

class ParseState {
  public:
    Token::Type_e type;
    long int num_value;
    int decimal_pt_pos;
    std::string str_value = "";
    char string_quote;
};

class Parser {
  private:
    std::string buffer;
    Token head;
    Node* tree;
    ParseState state;
    
  public:
    Parser(
        Node* _tree
        ) :
      head(),
      tree(_tree) {}
    
    int parse_line();
    Token get_token_list();
};
