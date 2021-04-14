#ifndef TOOLS_HPP
#define TOOLS_HPP

#include <string>
#include <functional>
#include <iostream>
#include <sstream>

namespace savchuk
{
  int convertToNumber(const std::string& order);
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
    std::ostringstream buf;
    while (first != last)
    {
      buf << *first << delim;
      ++first;
    }
    buf << '\n';
    os << buf.str();
  }
}

#endif