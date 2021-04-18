#ifndef SORT_HPP
#define SORT_HPP

#include <functional>
#include <iostream>
namespace ferapontov
{
  template< typename T, typename Strat>
  void sort(typename Strat::container_t& arr, std::function< bool(T, T) > cmp)
  {
    typename Strat::iterator_t size = Strat::end(arr);
    for(typename Strat::iterator_t i = Strat::begin(arr); i != size; i++)
    {
      typename Strat::iterator_t j = i;
      for(j++; j != size; j++)
      {
        if(cmp(Strat::element(arr, i), Strat::element(arr, j)))
        {
          std::swap(Strat::element(arr, i), Strat::element(arr, j));
        }
      }
    }
  }
}

#endif
