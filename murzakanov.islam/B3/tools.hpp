#ifndef TOOLS_HPP
#define TOOLS_HPP

#include <iosfwd>

namespace murzakanov
{
  constexpr size_t getFactorial(const size_t num)
  {
    if (num == 1)
    {
      return 1;
    }
    return num * getFactorial(num - 1);
  }
  std::istream& readName(std::istream& in, std::string& name);
  bool checkIsNum(const std::string& number);
  bool checkIsSpace(const std::string& arg);
}

#endif
