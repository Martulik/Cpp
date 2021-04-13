#ifndef STRATEGY_HPP
#define STRATEGY_HPP

#include <vector>
#include <forward_list>

namespace diurdeva {

  template< typename T >
  struct indexAccess {
    using type = T;
    using iterator = size_t;
    using container_type = std::vector< T >;

    static iterator begin(container_type &data)
    {
      return 0;
    }

    static iterator end(container_type &data)
    {
      return data.size();
    }

    static type &getElement(container_type &data, iterator i)
    {
      return data[i];
    }
  };

  template< typename T >
  struct atAccess {
    using type = T;
    using iterator = size_t;
    using container_type = std::vector< T >;

    static iterator begin(container_type &data)
    {
      return 0;
    }

    static iterator end(container_type &data)
    {
      return data.size();
    }

    static type &getElement(container_type &data, iterator i)
    {
      return data.at(i);
    }
  };

  template< typename T >
  struct iteratorAccess {
    using type = T;
    using container_type = std::forward_list< T >;
    using iterator = typename std::forward_list< T >::iterator;

    static iterator begin(container_type &data)
    {
      return data.begin();;
    }

    static iterator end(container_type &data)
    {
      return data.end();
    }

    static type &getElement(container_type &, iterator &i)
    {
      return *i;
    }
  };
}

#endif
