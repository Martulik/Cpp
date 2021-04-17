#ifndef TOOLS_HPP
#define TOOLS_HPP

#include <functional>
#include <string>
#include <iostream>
#include "sorting.hpp"
#include "strategy.hpp"

namespace murzakanov
{
  void fillRandom(double* array, int size);
  bool checkIsNumber(const std::string& str);
  bool checkForSpaces(const std::string& str);

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
  std::function< bool(T, T) > getSortMode(const std::string& order)
  {
    if (order == "ascending")
    {
      return std::greater< T >();
    }
    if (order == "descending")
    {
      return std::less< T >();
    }
    return nullptr;
  }
}

#endif
