#ifndef STRING_CONVERT_HPP
#define STRING_CONVERT_HPP

#include <string>
#include <boost/optional.hpp>

namespace shilyaev {
  boost::optional< int > toNatural(const char *string);
}

#endif
