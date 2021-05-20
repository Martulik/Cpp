#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <iosfwd>

namespace razukrantov
{
  constexpr unsigned long long getFactorial(const unsigned int index)
  {
    unsigned long long result = 1;
    for (unsigned int i = index; i > 0; --i)
    {
      result *= i;
    }
    return result;
  }

  std::istream& readName(std::istream& in, std::string& name);
  void invalidCommand(std::ostream& out);
  void invalidBookmark(std::ostream& out);
  void invalidStep(std::ostream& out);
  void empty(std::ostream& out);
}

#endif
