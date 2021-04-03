#ifndef INSERT_SORT_HPP
#define INSERT_SORT_HPP

#include <utility>
#include <functional>

namespace doroshin {
  template< typename T, typename S, typename Cmp >
  void insert_sort(typename S::container_t& cont, typename S::iterator_t begin, typename S::iterator_t end, Cmp cmp = std::less< T >())
  {
    using std::swap; // lookup for both std::swap and doroshin::swap
    using It = typename S::iterator_t;
    for(It i = begin; i != end; ++i) {
      for(It j = i; j > begin; --j) {
        T& lhs = S::get(cont, j - 1);
        T& rhs = S::get(cont, j);
        if(cmp(lhs, rhs))
          break;
        swap(lhs, rhs);
      }
    }
  }
}

#endif // INSERT_SORT_HPP
