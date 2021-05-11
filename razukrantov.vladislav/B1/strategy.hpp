#ifndef STRATEGY_HPP
#define STRATEGY_HPP

#include <vector>
#include <forward_list>

namespace razukrantov
{
  template< typename T >
  struct bracketsAccess
  {
    using iterator = size_t;
    using container = std::vector<T>;

    static iterator begin(const container&)
    {
      return 0;
    }

    static iterator end(const container& container)
    {
      return container.size();
    }

    static T& get(container& container, iterator& iterator)
    {
      return container[iterator];
    }
  };

  template < typename T >
  struct atAccess
  {
    using iterator = size_t;
    using container = std::vector< T >;

    static iterator begin(const container&)
    {
      return 0;
    }

    static iterator end(const container& container)
    {
      return container.size();
    }
    static T& get(container& container, iterator& iterator)
    {
      return container.at(iterator);
    }
  };

  template < typename T >
  struct iteratorAccess
  {
    using container = std::forward_list< T >;
    using iterator = typename container::iterator;

    static iterator begin(container& container)
    {
      return container.begin();
    }
    static iterator end(container& container)
    {
      return container.end();
    }
    static T& get(container&, iterator& iterator)
    {
      return *iterator;
    }
  };
}

#endif
