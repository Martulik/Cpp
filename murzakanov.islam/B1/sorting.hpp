#ifndef SORTING_HPP
#define SORTING_HPP



namespace murzakanov
{
  template < class Strategy >
  void sort(typename Strategy::store_type& store, const std::string& order)
  {
    typename Strategy::iterator end = Strategy::end(store);
    for (typename Strategy::iterator i = Strategy::begin(store); i != end; i++)
    {
      typename Strategy::iterator j = i;
      for (j++; j != end; j++)
      {
        if (((order == "ascending") && (Strategy::get(store, i) > Strategy::get(store, j))) ||
          ((order == "discending") && (Strategy::get(store, i) < Strategy::get(store, j))))
        {
          std::swap(Strategy::get(store, i), Strategy::get(store, j));
        }
      }
    }
  }
}

#endif
