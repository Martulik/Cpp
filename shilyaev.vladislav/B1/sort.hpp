#ifndef SORT_HPP
#define SORT_HPP

#include <algorithm>
#include <functional>
#include "iterator-print.hpp"

namespace shilyaev {

  template < typename Iterator >
  Iterator incremented(Iterator iterator)
  {
    return ++iterator;
  }

  template < typename AccessStrategy >
  void bubbleSort(typename AccessStrategy::Collection &collection,
      const std::function< bool(typename AccessStrategy::Item, typename AccessStrategy::Item) > &compare)
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
        if (compare(next, current)) {
          std::swap(current, next);
        }
      }
      end = i;
    }
  }

}

#endif
