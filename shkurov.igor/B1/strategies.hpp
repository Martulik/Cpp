#ifndef STRATEGIES_HPP
#define STRATEGIES_HPP

#include <vector>
#include <forward_list>

namespace shkurov
{
  template< typename T >
  struct strategyIndex
  {
    using strategyType = T;
    using iterator = size_t;
    using container = std::vector< T >;

    static iterator begin(container &cont)
    {
      return 0;
    }

    static iterator end(container &cont)
    {
      return cont.size();
    }

    static T& get(container &cont, iterator iter)
    {
      return cont[iter];
    }
  };

  template< typename T >
  struct strategyAt
  {
    using strategyType = T;
    using iterator = size_t;
    using container = std::vector< T >;

    static iterator begin(container &cont)
    {
      return 0;
    }

    static iterator end(container &cont)
    {
      return cont.size();
    }

    static T& get(container &cont, iterator iter)
    {
      return cont.at(iter);
    }
  };

  template< typename T >
  struct strategyIterator
  {
    using strategyType = T;
    using iterator = typename std::forward_list< T >::iterator;
    using container = std::forward_list< T >;

    static iterator begin(container &cont)
    {
      return cont.begin();
    }

    static iterator end(container &cont)
    {
      return cont.end();
    }

    static T& get(container &cont, iterator iter)
    {
      return *iter;
    }
  };
}

#endif
