#ifndef ITERATOR_ADVANCE_HPP
#define ITERATOR_ADVANCE_HPP

#include <iterator>

namespace shilyaev {
  template < typename Iterator >
  Iterator safeAdvance(Iterator iterator, int n, const Iterator &begin, const Iterator &end)
  {
    while (n > 0 && std::next(iterator) != end) {
      --n;
      ++iterator;
    }
    while (n < 0 && iterator != begin) {
      ++n;
      --iterator;
    }
    return iterator;
  }
}

#endif
