#ifndef SORTING_HPP
#define SORTING_HPP

#include <iostream>

namespace razukrantov
{
  template < typename Strategy >
  void sort(typename Strategy::container& container, const std::function< bool(typename Strategy::type, typename Strategy::type) > compare)
  {
    typename Strategy::iterator i = Strategy::begin(container);
    typename Strategy::iterator size = Strategy::end(container);
    for (i; i != size; i++)
    {
      typename Strategy::iterator j = i;
      for (j++, j != size, j++)
      {
        if (compare(Strategy::get(container, i), Strategy::get(container, j)
        {
          std::swap(Strategy::get(container, i), Strategy::get(container, j));
        }
      }
    }
  }
}

#endif
