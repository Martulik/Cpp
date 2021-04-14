#ifndef ACCESS_POLICY_HPP
#define ACCESS_POLICY_HPP

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
    
    static iterator begin(container& cnt)
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

    static iterator begin(container& cnt)
    {
      return 0;
    }
    static iterator end(container& cnt)
    {
      return cnt.size();
    }
    static T& get(container& cnt, iterator it)
    {
      return cnt.at(iter);
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
    static T& get(container& cnt, iterator it)
    {
      return *iter;
    }
  };
}

#endif