#ifndef STRATEGIES_HPP
#define STRATEGIES_HPP

#include <vector>
#include <forward_list>

namespace borisova
{
  template < typename T >
  struct bracketStrategy
  {
    using container = std::vector< T >;
    using iterator = size_t;

    static iterator begin(const container&)
    {
      return 0;
    }

    static iterator end(const container& vector)
    {
      return vector.size();
    }

    static T& get(container& vector, iterator& i)
    {
      return vector[i];
    }
  };

  template < typename T >
  struct atStrategy
  {
    using container = std::vector< T >;
    using iterator = size_t;

    static iterator begin(const container&)
    {
      return 0;
    }

    static iterator end(const container& vector)
    {
      return vector.size();
    }

    static T& get(container& vector, iterator& i)
    {
      return vector.at(i);
    }
  };

  template < typename T >
  struct listStrategy
  {
    using container = std::forward_list< T >;
    using iterator = typename std::forward_list< T >::iterator;

    static iterator begin(container& list)
    {
      return list.begin();
    }

    static iterator end(container& list)
    {
      return list.end();
    }

    static T& get(container&, iterator& iter)
    {
      return *iter;
    }
  };
}

#endif
