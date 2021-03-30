#include "strategy.hpp"

template < class Strategy >
void sort(typename Strategy::store_type& store, const std::string& order)
{
  typename Strategy::iterator i = Strategy::begin(store);
  typename Strategy::iterator end = Strategy::end(store);
  for (i; i < end; i++)
  {
    typename Strategy::iterator j = i + 1;
    for (j; j < end - 1; j++)
    { 
      if (order == "ascending")
      {
        if (Strategy::get(store, i) > Strategy::get(store, j))
        {
          std::swap(Strategy::get(store, i), Strategy::get(store, j));
        }
      }
      if (order == "discending")
      {
        if (Strategy::get(store, i) < Strategy::get(store, j))
        {
          std::swap(Strategy::get(store, i), Strategy::get(store, j));
        }
      }   
    }
  }
}

