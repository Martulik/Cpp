#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <cstddef>
#include <ostream>

namespace razukrantov
{
  constexpr size_t getFactorial(const size_t index)
  {
    size_t result = 1;
    for (size_t i = index; i > 0; --i)
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
