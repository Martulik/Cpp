#ifndef SORT_HPP
#define SORT_HPP

#include <functional>

namespace diurdeva {
  template< typename Strategy >
  void sorting(typename Strategy::container_type &collection,
               const std::function< bool(typename Strategy::type, typename Strategy::type) > compare)
  {
    using iter = typename Strategy::iterator;
    iter begin = Strategy::begin(collection);
    iter end = Strategy::end(collection);
    for (iter i = begin; i != end; ++i) {
      iter i2 = i;
      for (i2++; i2 != end; ++i2) {
        if (compare(Strategy::getElement(collection, i2), Strategy::getElement(collection, i))) {
          std::swap(Strategy::getElement(collection, i2), Strategy::getElement(collection, i));
        }
      }
    }
  }
}

#endif
