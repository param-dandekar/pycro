#include <stdexcept>

class LexerError : public std::exception {
  private:
    const std::string message;
  public:
    LexerError(const std::string& msg);
    LexerError(const std::string& msg, const std::string& reason);
    const char* what(); 
};

class SyntaxError : public std::exception {
  private:
    const std::string message = "Syntax error";
  public:
    const char* what(); 
};

