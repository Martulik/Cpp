#ifndef COMPARE_FUNCTION_HPP
#define COMPARE_FUNCTION_HPP

#include <string>
#include <boost/optional.hpp>

namespace shilyaev {
  template < typename T >
  boost::optional< std::function< bool(T, T) > > getCompareFunction(const std::string &string)
  {
    if (string == "ascending") {
      return boost::optional< std::function< bool(T, T) > >(std::less< T >());
    } else if (string == "descending") {
      return boost::optional< std::function< bool(T, T) > >(std::greater< T >());
    }
    return boost::optional< std::function< bool(T, T) > >();
  }
}

#endif
