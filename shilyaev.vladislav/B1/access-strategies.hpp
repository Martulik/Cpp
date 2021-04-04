#ifndef ITERATOR_STRATEGIES_HPP
#define ITERATOR_STRATEGIES_HPP

#include <vector>
#include <forward_list>

template < typename T >
struct VectorBracketsStrategy {
  using Item = T;
  using Collection = typename std::vector< Item >;
  using Iterator = size_t;

  static Iterator begin(__attribute__((unused)) const Collection &collection)
  {
    return 0;
  }

  static Iterator end(const Collection &collection)
  {
    return collection.size();
  }

  static Item &get(Collection &collection, const Iterator &iterator)
  {
    return collection[iterator];
  }
};

template < typename T >
struct VectorAtStrategy {
  using Item = T;
  using Collection = typename std::vector< Item >;
  using Iterator = size_t;

  static Iterator begin(__attribute__((unused)) const Collection &collection)
  {
    return 0;
  }

  static Iterator end(const Collection &collection)
  {
    return collection.size();
  }

  static Item &get(Collection &collection, const Iterator &iterator)
  {
    return collection.at(iterator);
  }
};

template < typename T >
struct ForwardListIteratorStrategy {
  using Item = T;
  using Collection = typename std::forward_list< Item >;
  using Iterator = typename Collection::iterator;

  static Iterator begin(Collection &collection)
  {
    return collection.begin();
  }

  static Iterator end(Collection &collection)
  {
    return collection.end();
  }

  static Item &get(__attribute__((unused)) Collection &collection, const Iterator &iterator)
  {
    return *iterator;
  }
};

#endif
