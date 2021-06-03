#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <functional>
#include <algorithm>
#include <cassert>
#include <string>

namespace pozdnyakov
{
  void checkLineEnding(const std::string& str);
  bool compChar(char a, char b);
  bool compCharNeg(char a, char b);
  void removeWS(std::string& str);
}

#endif
