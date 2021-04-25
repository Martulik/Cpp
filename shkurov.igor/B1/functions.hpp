#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <vector>
#include <functional>
#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <memory>
#include <string>

#include "strategies.hpp"

namespace shkurov
{
  template < class Strategy, typename T >
  void selectionSort(typename Strategy::container& cont, std::function< bool(T, T) > cmp)
  {
    using iterator_t = typename Strategy::iterator;
    iterator_t end = Strategy::end(cont);
    iterator_t begin = Strategy::begin(cont);

    if (cmp == nullptr)
    {
      throw std::invalid_argument("Incorrect comparsion method");
    }

    for (iterator_t i = begin; i != end; i++)
    {
      iterator_t swapId = i;
      iterator_t j = i;
      for (j++; j != end; j++)
      {
        if (cmp(Strategy::get(cont, j), Strategy::get(cont, swapId)))
        {
          swapId = j;
        }
      }
      if (Strategy::get(cont, i) != Strategy::get(cont, swapId))
      {
        std::swap(Strategy::get(cont, i), Strategy::get(cont, swapId));
      }
    }
  }

  template < typename T >
  void printContainer(const T& cont, char separator)
  {
    using iterator_t = typename T::const_iterator;

    for (iterator_t it = cont.begin(); it != cont.end(); it++)
    {
      if (separator != static_cast< char >(0))
      {
        std::cout << *it << separator;
      }
      std::cout << *it;
    }
    std::cout << '\n';
  }



  template < typename T >
  std::function< bool(T, T) > comparsionMethod(const char* cmd)
  {
    if (!strcmp(cmd, "ascending"))
    {
      return std::less< T >();
    }
    else if (!strcmp(cmd, "descending"))
    {
      return std::greater< T >();
    }

    return nullptr;
  }

  void fillRandom(double *array, int size);
  bool containsSpaces(size_t argsCount, char* argv[]);
  bool isNumber(const std::string& str);
}

#endif
