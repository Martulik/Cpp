#ifndef SORT_STRATEGIES_HPP
#define SORT_STRATEGIES_HPP

#include <vector>
#include <forward_list>

namespace doroshin {
  // Strategy fields
  // container_t - underlying container
  // iterator_t - iterator to use, must support increment
  // iterator_t begin(container_t&) - get begin iter
  // iterator_t end(container_t&) - get end iter
  // T& get(container_t&, iterator_t) - get item via the iterator

  template< typename T >
  struct VectorIndexStrat
  {
    using container_t = std::vector< T >;
    using iterator_t = size_t;

    static inline iterator_t begin(container_t&)
    {
      return 0;
    }

    static inline iterator_t end(container_t& vec)
    {
      return vec.size();
    }

    static inline T& get(container_t& vec, iterator_t it)
    {
      return vec[it];
    }
  };

  template< typename T >
  struct VectorAtStrat
  {
    using container_t = std::vector< T >;
    using iterator_t = size_t;

    static inline iterator_t begin(container_t&)
    {
      return 0;
    }

    static inline iterator_t end(container_t& vec)
    {
      return vec.size();
    }

    static inline T& get(container_t& vec, iterator_t it)
    {
      return vec.at(it);
    }
  };

  template< typename T >
  struct ListIterStrat
  {
    using container_t = std::forward_list< T >;
    using iterator_t = typename std::forward_list< T >::iterator;

    static inline iterator_t begin(container_t& list)
    {
      return list.begin();
    }

    static inline iterator_t end(container_t& list)
    {
      return list.end();
    }

    static inline T& get(container_t&, iterator_t it)
    {
      return *it;
    }
  };
}

#endif // SORT_STRATEGIES_HPP
