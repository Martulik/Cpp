#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <vector>
#include <functional>
#include <iostream>
#include <stdexcept>
#include <ctime>
#include <cstring>
#include "strategies.hpp"

namespace pyatizbyantsev
{
  template < typename T >
  std::function< bool(T, T) > sortMode(const char* mode)
  {
    if (!strcmp(mode, "ascending"))
    {
      return std::less< T >();
    }
    else if (!strcmp(mode, "descending"))
    {
      return std::greater< T >();
    }
      throw std::invalid_argument("Invalid sorting mode");
    }

  template < typename Strategy, typename T >
  void sort(typename Strategy::container& arr, std::function< bool(T, T) > cmp)
  {
    using iterator_t = typename Strategy::iterator;
    iterator_t begin = Strategy::begin(arr);
    iterator_t end = Strategy::end(arr);

    for (iterator_t i = begin; i != end; i++)
    {
      iterator_t j = i;
      for (j++; j != end; j++)
      {
        if (!cmp(Strategy::get(arr, i), Strategy::get(arr, j)))
        {
          std::swap(Strategy::get(arr, i), Strategy::get(arr, j));
        }
      }
    }
  }

  template < typename T >
  void print(T begin, T end, const char* delim)
  {
    while (begin != end)
    {
      std::cout << *begin << delim;
      ++begin;
    }
    std::cout << '\n';
  }

  bool checkSpaces(const char* str);
  bool checkNumber(const char* str);
}

#endif
