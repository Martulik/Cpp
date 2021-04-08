#ifndef SORT_HPP
#define SORT_HPP

#include <algorithm>
#include "iterator-print.hpp"

namespace shilyaev {

  template < typename Iterator >
  Iterator incremented(Iterator iterator)
  {
    return ++iterator;
  }

  template < typename AccessStrategy, typename Order >
  void bubbleSort(typename AccessStrategy::Collection &collection)
  {
    using Item = typename AccessStrategy::Item;
    using Iterator = typename AccessStrategy::Iterator;
    const Iterator begin = AccessStrategy::begin(collection);
    Iterator end = AccessStrategy::end(collection);
    while (begin != end) {
      Iterator i = begin;
      for (; incremented(i) != end; i++) {
        Item &current = AccessStrategy::get(collection, i);
        Item &next = AccessStrategy::get(collection, incremented(i));
        if (!Order::isOrdered(current, next)) {
          std::swap(current, next);
        }
      }
      end = i;
    }
  }

}

#endif
