#pragma once

#include <string>

class Interpreter {
  private:
    const std::string name = "PyCro";
    const std::string version = "v0.1";

    void print_info();

  public:
    void run();
};
