#include <string>

enum TokenType {
  INTEGER,
  OPERATOR
};

class Token {
  private:
    TokenType type;
    std::string name;
    bool is_valid_token_name(const std::string name);

  public:
    Token(TokenType _type, const std::string& _name);
};

