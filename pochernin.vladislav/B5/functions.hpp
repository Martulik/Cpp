#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <string>

#include "shape.hpp"

namespace pochernin
{
  int getTaskNumber(const char* string);
  bool isNumber(const std::string& str);
  unsigned int sumVertices(unsigned int sum, const Shape& shape);
}

#endif
