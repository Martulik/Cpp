#ifndef TOOLS_HPP
#define TOOLS_HPP

#include <string>
#include <functional>
#include <iostream>
#include <random>

namespace savchuk
{
  size_t convertToNumber(const std::string& order);
  void fillRandom(double* array, size_t size);

  template< typename T >
  std::function< bool(const T&, const T&) > getCompare(const std::string& order)
  {
    if (order == "ascending")
    {
      return std::less< T >();
    }
    if (order == "descending")
    {
      return std::greater< T >();
    }
    throw std::invalid_argument("invalid sort order");
  }
  template< typename Iterator >
  void print(Iterator first, Iterator last, std::ostream& os)
  {
    char delim = ' ';
    while (first != last)
    {
      os << *first << delim;
      ++first;
    }
    os << '\n';
  }
}

#endif