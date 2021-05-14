#ifndef SORTING_HPP
#define SORTING_HPP

#include <functional>

#include "strategy.hpp"

namespace razukrantov
{
  template < typename Strategy, typename Compare >
  void sort(typename Strategy::container& container, Compare compare)
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
