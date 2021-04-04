#ifndef SORT_HPP
#define SORT_HPP

#include <algorithm>
#include "iterator-utils.hpp"

template < typename Strategy, typename Order >
void bubbleSort(typename Strategy::Collection &collection)
{
  using Item = typename Strategy::Item;
  using Iterator = typename Strategy::Iterator;
  Iterator begin = Strategy::begin(collection);
  Iterator end = Strategy::end(collection);
  while (begin != end) {
    Iterator i = begin;
    for (; advanced(i) != end; i++) {
      Item &current = Strategy::get(collection, i);
      Item &next = Strategy::get(collection, advanced(i));
      if (!Order::isOrdered(current, next)) {
        std::swap(current, next);
      }
    }
    end = i;
  }
}

#endif
