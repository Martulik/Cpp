#ifndef TOOLS_HPP
#define TOOLS_HPP

#include <cstddef>
#include <sstream>
#include <string>
#include <iostream>

namespace murzakanov
{
  constexpr size_t getValue(const size_t num)
  {
    if (num == 1)
    {
      return 1;
    }
    return num * getValue(num - 1);
  }
  std::istream& readName(std::istream& in, std::string& name, std::ostream& out);
  bool checkIsNum(const std::string& number);
  bool checkIsSpace(const std::string& arg);
}

#endif
