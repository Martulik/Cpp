#ifndef ACCESS_POLICIES_HPP
#define ACCESS_POLICIES_HPP

#include <cstddef>
#include <vector>
#include <forward_list>

namespace savchuk
{
  template< typename T >
  struct IndexVectorPolicy
  {
    using container = std::vector< T >;
    using iterator = size_t;

    static iterator begin(container&)
    {
      return 0;
    }
    static iterator end(container& cnt)
    {
      return cnt.size();
    }
    static T& get(container& cnt, iterator it)
    {
      return cnt[it];
    }
  };

  template< typename T >
  struct AtVectorPolicy
  {
    using container = std::vector< T >;
    using iterator = size_t;

    static iterator begin(container&)
    {
      return 0;
    }
    static iterator end(container& cnt)
    {
      return cnt.size();
    }
    static T& get(container& cnt, iterator it)
    {
      return cnt.at(it);
    }
  };

  template< typename T >
  struct IteratorFwListPolicy
  {
    using container = std::forward_list< T >;
    using iterator = typename container::iterator;

    static iterator begin(container& cnt)
    {
      return cnt.begin();
    }
    static iterator end(container& cnt)
    {
      return cnt.end();
    }
    static T& get(container&, iterator it)
    {
      return *it;
    }
  };
}

#endif
