#include <string>

#include "util.h"

#include "number.h"
#include "integer_t.h"
#include "float_t.h"

template <class py_int>
std::string Number<py_int>::to_str() {
  return "int";
}
/*
template <class py_float>
std::string Number<py_float>::to_str() {
  return "float";
}
*/
