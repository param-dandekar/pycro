#include "quotestack.h"

#include <iostream>
#include <string>

std::string QuoteStack::to_str() {
  std::string quotes = "";
  for(int i = 0; i < stackptr; i++) {
    quotes += stack[i];
  }
  return quotes;
}

int QuoteStack::push(char quote) {
  if(stackptr == MAX_QUOTES) return 1;
  stack[stackptr++] = quote;
  return 0;
}

char QuoteStack::peek() {
  if(!stackptr) return 1;
  return stack[stackptr-1];
}

char QuoteStack::pop() {
  if(!stackptr) return 1;
  return stack[--stackptr];
}

bool QuoteStack::is_empty() {
  return (stackptr == 0);
}

bool QuoteStack::is_full() {
  return (stackptr == MAX_QUOTES);
}

void QuoteStack::clear() {
  stackptr = 0;
}
