#ifndef TOOLS_HPP
#define TOOLS_HPP

#include <cstring>
#include <functional>
#include <iostream>
#include <vector>

namespace savchuk
{
  size_t convertToNumber(const char* order);
  void fillRandom(double* array, size_t size);
  void removeEvenNumbers(std::vector< int >& vec);
  void addExtraNumbers(std::vector< int >& vec);

  template< typename T >
  std::function< bool(const T&, const T&) > getCompare(const char* order)
  {
    if (!std::strcmp(order, "ascending"))
    {
      return std::less< T >();
    }
    if (!std::strcmp(order, "descending"))
    {
      return std::greater< T >();
    }
    throw std::invalid_argument("invalid sort order");
  }
  template< typename Iterator >
  void print(Iterator first, Iterator last, std::ostream& os, const char* delim = "")
  {
    while (first != last)
    {
      os << *first << delim;
      ++first;
    }
    os << '\n';
  }
}

#endif
