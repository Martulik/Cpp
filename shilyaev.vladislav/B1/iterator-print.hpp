#ifndef ITERATOR_PRINT_HPP
#define ITERATOR_PRINT_HPP

#include <iostream>

namespace shilyaev {
  template < typename Iterator >
  void print(Iterator begin, const Iterator &end, const std::string &sep = " ", const std::string &ending = "\n")
  {
    for (; begin != end; begin++) {
      std::cout << *begin << sep;
    }
    std::cout << ending;
  }
}

#endif
