#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP
#include <string>
#include <vector>
#include "data-struct.hpp"

namespace lebedeva
{
  bool isNumber(std::string& str);
  bool isAcceplable(int key);
  void print(std::vector< DataStruct > data, std::ostream& out);
}

#endif
