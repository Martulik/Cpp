#ifndef STRATEGY_HPP
#define STRATEGY_HPP

#include <vector>
#include <forward_list>

namespace murzakanov
{
  template< class T >
  struct StrategyBrackets
  {
    using iterator = size_t;
    using store_type = typename std::vector< T >;

    static iterator begin(const store_type&)
    {
      return 0;
    }
    static iterator end(const store_type& store)
    {
      return store.size();
    }
    static T& get(store_type& store, iterator& iter)
    {
      return store[iter];
    }
  };

  template< class T >
  struct StrategyAt
  {
    using iterator = size_t;
    using store_type = typename std::vector< T >;

    static iterator begin(const store_type&)
    {
      return 0;
    }
    static iterator end(const store_type& store)
    {
      return store.size();
    }
    static T& get(store_type& store, iterator& iter)
    {
      return store.at(iter);
    }
  };

  template< class T >
  struct StrategyIter
  {
    using iterator = typename std::forward_list< T >::iterator;
    using store_type = std::forward_list< T >;
    static iterator begin(store_type& store)
    {
      return store.begin();
    }
    static iterator end(store_type& store)
    {
      return store.end();
    }
    static T& get(store_type&, iterator& iter)
    {
      return *iter;
    }
  };
}

#endif
