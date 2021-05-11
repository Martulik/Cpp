#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <ostream>
#include <functional>
#include <stdexcept>
#include <cstring>

namespace razukrantov
{
  template < typename T >
  std::function < bool(T, T) > getSortOrder(const char* order)
  {
    if (order == nullptr)
    {
      throw(std::invalid_argument("Incorrect order\n"));
    }
    if (!strcmp(order, "ascending"))
    {
      return std::greater< T >();
    }
    if (!strcmp(order, "descending"))
    {
      return std::less< T >();
    }
    throw(std::invalid_argument("Incorrect order\n"));
  }

  template < typename T >
  void print(const T& container, std::ostream& out)
  {
    using iterator = typename T::const_iterator;
    iterator size = container.end();
    for (iterator cur = container.begin(); cur != size; cur++)
    {
      out << *cur << " ";
    }
    out << "\n";
  }

  void fillRandom(double* array, int size);
  bool isNumber(const char* str);
  bool checkSpaces(const char* str);
}

#endif
