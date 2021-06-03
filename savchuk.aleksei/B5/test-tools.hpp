#ifndef TEST_TOOLS_HPP
#define TEST_TOOLS_HPP

#include "shape.hpp"

namespace savchuk
{
  void checkCorrectInput(const char* str);
  void checkIncorrectInput(const char* str);
  void checkRandomShape(const Shape& shape);
}

#endif
