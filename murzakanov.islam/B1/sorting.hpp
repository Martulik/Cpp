#ifndef SORTING_HPP
#define SORTING_HPP

#include <functional>

namespace murzakanov
{
  template < class Strategy, typename itemType >
  void sort(typename Strategy::store_type& store, std::function< bool(itemType, itemType) > cmp)
  {
    typename Strategy::iterator end = Strategy::end(store);
    for (typename Strategy::iterator i = Strategy::begin(store); i != end; i++)
    {
      typename Strategy::iterator j = i;
      for (j++; j != end; j++)
      {
        if (cmp(Strategy::get(store, i), Strategy::get(store, j)))
        {
          std::swap(Strategy::get(store, i), Strategy::get(store, j));
        }
      }
    }
  }
}

#endif
