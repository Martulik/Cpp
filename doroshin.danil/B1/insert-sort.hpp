#ifndef INSERT_SORT_HPP
#define INSERT_SORT_HPP

#include <utility>
#include <functional>

namespace doroshin {
  template< typename T, typename S, typename Cmp = std::less< T > >
  void insert_sort(typename S::container_t& cont, typename S::iterator_t begin, typename S::iterator_t end, Cmp cmp = std::less< T >())
  {
    using std::swap; // lookup for both std::swap and doroshin::swap
    using It = typename S::iterator_t;
    for(It i = begin; i != end; ++i) {
      T& i_val = S::get(cont, i);
      It j = begin;
      while(cmp(S::get(cont, j), i_val)) {
        j++;
      }
      while(j != i) {
        swap(S::get(cont, j), i_val);
        j++;
      }
    }
  }
}

#endif // INSERT_SORT_HPP
