#ifndef TOOLS_HPP
#define TOOLS_HPP

#include <string>
#include <iosfwd>

namespace savchuk
{
  constexpr size_t calcucateFactorial(size_t n)
  {
    size_t res = 1;
    for (size_t i = n; i > 0; --i)
    {
      res *= i;
    }
    return res;
  }

  std::string readNumber(std::istream& is);
  std::string readName(std::istream& is);
  std::string readMarkName(std::istream& is);
}

#endif
