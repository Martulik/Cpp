#ifndef ITERATOR_PRINT_HPP
#define ITERATOR_PRINT_HPP

#include <ios>

namespace shilyaev {
  template < typename Iterator >
  void print(Iterator begin, const Iterator &end, std::ostream &ostream,
      const std::string &sep = " ", const std::string &ending = "\n")
  {
    for (; begin != end; begin++) {
      ostream << *begin << sep;
    }
    ostream << ending;
  }
}

#endif
