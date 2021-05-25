#ifndef TEST_TOOLS_HPP
#define TEST_TOOLS_HPP

#include <iosfwd>

namespace savchuk
{
  void checkCorrectInput(std::istringstream& ss, const char* data);
  void checkIncorrectInput(std::istringstream& ss, const char* data);
  void checkInvalidKey(std::istringstream& ss, const char* data);
}

#endif
