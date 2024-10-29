#pragma once

#include <string>

#define MAX_QUOTES 100

class QuoteStack {
  private:
    char stack[MAX_QUOTES];
    int stackptr;

  public:
    QuoteStack() :
      stackptr(0) {}
    ~QuoteStack() {
    }
    
    std::string to_str();

    int push(char quote);
    char peek();
    char pop();
    bool is_empty();
    bool is_full();
    void clear();
};
