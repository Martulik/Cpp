#ifndef COMPARE_FUNCTION_HPP
#define COMPARE_FUNCTION_HPP

#include <functional>
#include <cstring>

namespace diurdeva {
  template< typename T >
  std::function< bool(T, T) > getCompare(const char *direction, Error &err)
  {
    if (!strcmp(direction, "ascending")) {
      return std::less< T >();
    } else if (!strcmp(direction, "descending")) {
      return std::greater< T >();
    }
    err.set("Incorrect argument\n");
    return nullptr;
  }
}

#endif
