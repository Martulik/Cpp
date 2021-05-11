#ifndef TOOLS_HPP
#define TOOLS_HPP

#include <functional>
#include <iostream>
#include <cstring>
#include "sorting.hpp"
#include "strategy.hpp"

namespace murzakanov
{
  void fillRandom(double* array, int size);
  bool checkIsNumber(const char* str);
  bool checkForSpaces(const char* str);

  template< typename T >
  void print(const T& store, std::ostream& out)
  {
    using iter = typename T::const_iterator;
    iter it = store.begin();
    iter end = store.end();
    while (it != end)
    {
      out << *it << " ";
      it++;
    }
    std::cout << "\n";
  }

  template < typename T >
  std::function< bool(T, T) > getSortMode(const char* order)
  {
    if (!strcmp(order, "ascending"))
    {
      return std::greater< T >();
    }
    if (!strcmp(order, "descending"))
    {
      return std::less< T >();
    }
    return nullptr;
  }
}

#endif
