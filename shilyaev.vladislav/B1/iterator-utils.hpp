#ifndef ITERATOR_UTILS_HPP
#define ITERATOR_UTILS_HPP

#include <iostream>

namespace shilyaev {

  template < typename T >
  void print(T t)
  {
    std::cout << t << ' ';
  }

  template <>
  void print< char >(char t);

  template < typename Iterator >
  void print(Iterator begin, const Iterator &end)
  {
    for (; begin != end; begin++) {
      print(*begin);
    }
    std::cout << '\n';
  }

  template < typename Iterator >
  Iterator incremented(Iterator iterator)
  {
    return ++iterator;
  }

}

#endif
