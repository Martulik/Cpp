#ifndef COMPARE_FUNCTION_HPP
#define COMPARE_FUNCTION_HPP

#include <cstring>
#include <boost/optional.hpp>

namespace shilyaev {
  template < typename T >
  boost::optional< std::function< bool(T, T) > > getCompareFunction(const char *string)
  {
    if (strcmp(string, "ascending") == 0) {
      return {std::less< T >()};
    } else if (strcmp(string, "descending") == 0) {
      return {std::greater< T >()};
    }
    return {};
  }
}

#endif
