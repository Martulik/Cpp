#ifndef TOOLS_HPP
#define TOOLS_HPP

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
}

#endif
