#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <vector>
#include <functional>
#include <iostream>

#include "strategies.hpp"

template < class Strategy, typename T >
void selectionSort(typename Strategy::container& cont, std::function< bool(T, T) > cmp)
{
  using iterator_t = typename Strategy::iterator;
  iterator_t end = Strategy::end(cont);
  iterator_t begin = Strategy::begin(cont);

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
    std::cout << *it << separator;
  }
  std::cout << '\n';
}



template < typename T >
std::function< bool(T, T) > comparsionMethod(const char* cmd)
{
  if (strcmp(cmd, "ascending"))
  {
    return std::greater< T >();
  }
  else if (strcmp(cmd, "descending"))
  {
    return std::less< T >();
  }
  else
  {
    throw "fuck you asshole >_<";
  }
}

#endif
