#ifndef COMPARATOR_HPP
#define COMPARATOR_HPP

#include <cstring>
#include <functional>

namespace lysenko
{
  template< typename T >
  std::function < bool(const T&, const T&) > getComparator (const char* order)
  {
    std::function < bool(const T&, const T&) > comparator = nullptr;
    if (strcmp(order, "ascending") == 0)
    {
      comparator = std::less< T >();
    }
    else if (strcmp(order, "descending") == 0)
    {
      comparator = std::greater< T >();
    }
    return comparator;
  }
}

#endif
