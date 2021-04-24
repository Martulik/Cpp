#ifndef TOOLS_HPP
#define TOOLS_HPP

#include <iostream>
#include <functional>
#include "Sort.hpp"
#include "strategy.hpp"

namespace diurdeva {
  void fillRandom(double *array, size_t size);
  bool checkIsNumber(const char* string);

  template< typename T >
  void print(const T &collection)
  {
    if (collection.empty()) {
      return;
    }

    for (const auto &i : collection) {
      std::cout << i << " ";
    }

    std::cout << '\n';
  }

  template< typename Strategy >
  void printAndSorted(typename Strategy::container_type collection,
                      const std::function< bool(typename Strategy::type, typename Strategy::type) > compare)
  {
    diurdeva::sorting< Strategy >(collection, compare);
    diurdeva::print(collection);
  }
}

#endif
