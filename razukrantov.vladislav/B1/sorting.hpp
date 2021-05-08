#ifndef SORTING_HPP
#define SORTING_HPP

#include <iostream>
#include <functional>

#include "strategy.hpp"

namespace razukrantov
{
  template < typename Strategy, typename T >
  void sort(typename Strategy::container& container, const std::function< bool(T, T) > compare)
  {
    typename Strategy::iterator begin = Strategy::begin(container);
    typename Strategy::iterator size = Strategy::end(container);
    for (typename Strategy::iterator i = begin; i != size; i++)
    {
      typename Strategy::iterator j = i;
      for (j++; j != size; j++)
      {
        if (compare(Strategy::get(container, i), Strategy::get(container, j)))
        {
          std::swap(Strategy::get(container, i), Strategy::get(container, j));
        }
      }
    }
  }
}

#endif
