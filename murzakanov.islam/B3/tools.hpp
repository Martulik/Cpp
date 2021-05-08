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
  void invalidBookmark(std::ostream& out);
  void empty(std::ostream& out);
  void invalidCommand(std::ostream& out);
  void invalidStep(std::ostream& out);
}

#endif
