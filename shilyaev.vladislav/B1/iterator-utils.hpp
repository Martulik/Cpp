#ifndef ITERATOR_UTILS_HPP
#define ITERATOR_UTILS_HPP

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

  template < typename Iterator >
  Iterator incremented(Iterator iterator)
  {
    return ++iterator;
  }

}

#endif
