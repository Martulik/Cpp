#ifndef TOOLS_HPP
#define TOOLS_HPP

#include <iostream>
#include <functional>
#include "sort.hpp"
#include "strategy.hpp"

namespace diurdeva {
  void fillRandom(double *array, size_t size);
  bool isNumber(const char* str);

  template< typename T >
  void print(const T &collection)
  {
    if (collection.empty()) {
      return;
    }

    for (auto &&i: collection) {
      std::cout << i << " ";
    }

    std::cout << '\n';
  }

  template< typename Strategy >
  void printAndSort(typename Strategy::container_type collection,
                    const std::function< bool(typename Strategy::type, typename Strategy::type) > compare)
  {
    diurdeva::sort< Strategy >(collection, compare);
    diurdeva::print(collection);
  }
}

#endif
