#ifndef STRING_CONVERT_HPP
#define STRING_CONVERT_HPP

#include <boost/optional.hpp>

namespace shilyaev {
  boost::optional< int > toNatural(const char *string);
}

#endif
