#ifndef SORT_HPP
#define SORT_HPP

#include <algorithm>
#include "iterator-utils.hpp"

template < typename AccessStrategy, typename Order >
void bubbleSort(typename AccessStrategy::Collection &collection)
{
  using Item = typename AccessStrategy::Item;
  using Iterator = typename AccessStrategy::Iterator;
  Iterator begin = AccessStrategy::begin(collection);
  Iterator end = AccessStrategy::end(collection);
  while (begin != end) {
    Iterator i = begin;
    for (; advanced(i) != end; i++) {
      Item &current = AccessStrategy::get(collection, i);
      Item &next = AccessStrategy::get(collection, advanced(i));
      if (!Order::isOrdered(current, next)) {
        std::swap(current, next);
      }
    }
    end = i;
  }
}

#endif
