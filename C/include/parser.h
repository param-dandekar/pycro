#include <string>

#include "util.h"

#include "parse_state.h"
#include "node.h"
#include "token.h"

class Parser {
  private:
    std::string buffer;
    Token head;
    Node* tree;
    ParseState state;
    
  public:
    Parser() :
      head(),
      tree(),
      state() { std::cout<< "why\n"; }
    Parser(
        Node* _tree
        ) :
      head(),
      tree(_tree) {}
    
    int parse_line();
    void reset_state();
    Token get_token_list();
};
