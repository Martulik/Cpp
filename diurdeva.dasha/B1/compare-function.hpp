#ifndef COMPARE_FUNCTION_HPP
#define COMPARE_FUNCTION_HPP

#include<functional>
#include <cstring>

namespace diurdeva {
  template< typename T >
  std::function< bool(T, T) > getCompare(const char *direction)
  {
    const char ascending[] = "ascending";
    const char descending[] = "descending";
    if (!strcmp(direction, ascending)) {
      return std::less< T >();
    } else if (!strcmp(direction, descending)) {
      return std::greater< T >();
    }
    return nullptr;
  }
}

#endif
