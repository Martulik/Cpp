#ifndef TOOLS_HPP
#define TOOLS_HPP

#include <string>
#include <functional>

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
}

#endif