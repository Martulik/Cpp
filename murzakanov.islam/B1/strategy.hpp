#ifndef STRATEGY_HPP
#define STRATEGY_HPP

template< class T >
struct StrategyBrackets
{
  using iterator = unsigned int;
  using store_type = typename std::vector< T >;
  static iterator begin(const store_type & store)
  {
    return 0;
  }
  static iterator end(const store_type & store)
  {
    return store.size();
  }
  static T & get(store_type & store, iterator & iter)
  {
    return store[iter];
  }
}

#endif
