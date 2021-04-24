#ifndef COMPARE_FUNCTION_HPP
#define COMPARE_FUNCTION_HPP

#include <string>
#include <boost/optional.hpp>

namespace shilyaev {
  template < typename T >
  boost::optional< std::function< bool(T, T) > > getCompareFunction(const char *string)
  {
    if (string == std::string("ascending")) {
      return {std::less< T >()};
    } else if (string == std::string("descending")) {
      return {std::greater< T >()};
    }
    return {};
  }
}

#endif
