#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <iostream>
#include <functional>
#include <stdexcept>
#include <cstring>

namespace razukrantov
{
  template <typename T >
  std::function < bool(T, T) > getSortOrder(const char* order)
  {
    if (order == nullptr)
    {
      throw(std::invalid_argument("Incorrect order\n"));
    }
    if (!strcmp(order, "ascending"))
    {
      return std::less< T >();
    }
    if (!strcmp(order, "descending"))
    {
      return std::greater< T >();
    }
    throw std::invalid_argument("Incorrect order\n");
  }

  template < typename T >
  void print(const T& container)
  {
    using iterator = typename T::const_iterator;
    iterator size = container.end();
    for (iterator cur = container.begin(); cur != size; cur++)
    {
      std::cout << *cur << " ";
    }
    std::cout << "\n";
  }

  void fillRandom(double* array, int size);
  bool isNumber(const char* str);
}

#endif
