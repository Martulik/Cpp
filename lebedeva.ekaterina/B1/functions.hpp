#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP
#include <iostream>
#include <functional>
#include <cstring>
#include "access.hpp"

namespace lebedeva
{
  bool isNumber(const char* num);
  void checkNumOfArgs(int argc, int expected);
  void fillRandom(double* array, int size);

  template < typename T >
  std::function< bool(T, T) > getSortOrder(const char* order)
  {
    const char* ascending = "ascending";
    const char* descending = "descending";
    if (!strcmp(order, ascending))
    {
      return std::less< T >();
    }
    else if (!strcmp(order, descending))
    {
      return std::greater< T >();
    }
    else
    {
      throw std::invalid_argument("Invalid sorting order");
    }
  }

  template< class T >
  void print(T& data, std::ostream& out)
  {
    for (auto i = data.begin(); i != data.end(); i++)
    {
      out << *i << " ";
    }
    out << '\n';
  }
}
#endif
