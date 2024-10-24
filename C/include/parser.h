#include <string>

#include "node.h"
#include "token.h"

class Parser {
  private:
    std::string buffer;
    Token head;
    Node* tree;
    
  public:
    Parser(
        Node* _tree
        ) :
      tree(_tree),
      head() {}

    int readline();
    Token get_token_list();
};
