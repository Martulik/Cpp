#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <iostream>
#include <cstring>
#include <functional>
#include <random>

namespace ferapontov
{
  template< typename T >
  std::function< bool(T, T) > getSortMode(const char* mode)
  {
    if (strcmp(mode, "ascending") && strcmp(mode, "descending"))
    {
      std::cerr << "Invalid sorting mode";
      std::exit(1);
    }
    if (!strcmp(mode, "ascending"))
    {
      return std::less< T >();
    }
    else
    {
      return std::greater< T >();
    }
  }

  template< typename T>
  void print(const T& arr)
  {
    for (auto it = arr.begin(); it != arr.end(); ++it)
    {
      std::cout << *it << ' ';
    }
    std::cout << '\n';
  }

  void fillRandom(double* array, int size);
  void checkSpaces(const char* str);
  void checkNumber(const char* str);
}


#endif
