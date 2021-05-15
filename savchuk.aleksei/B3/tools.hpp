#ifndef TOOLS_HPP
#define TOOLS_HPP

#include <string>
#include <iosfwd>

namespace savchuk
{
  constexpr unsigned long long calcucateFactorial(unsigned int n)
  {
    unsigned long long res = 1;
    for (unsigned int i = n; i > 0; --i)
    {
      res *= i;
    }
    return res;
  }

  std::string readNumber(std::istream& is);
  std::string readName(std::istream& is);
  std::string readMarkName(std::istream& is);
  std::string readSteps(std::istream& is);
  std::string readPosition(std::istream& is);
}

#endif
