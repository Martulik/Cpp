#ifndef INSERT_SORT_HPP
#define INSERT_SORT_HPP

#include <utility>
#include <functional>

namespace doroshin {
  template< typename T, template< typename > typename S, typename Cmp = std::less< T > >
  void insert_sort(
      typename S< T >::container_t& cont,
      typename S< T >::iterator_t begin,
      typename S< T >::iterator_t end,
      Cmp cmp = std::less< T >()
  )
  {
    using std::swap; // lookup for both std::swap and doroshin::swap
    using It = typename S< T >::iterator_t;
    for(It i = begin; i != end; ++i) {
      T& i_val = S< T >::get(cont, i);
      It j = begin;
      while(cmp(S< T >::get(cont, j), i_val)) {
        j++;
      }
      while(j != i) {
        swap(S< T >::get(cont, j), i_val);
        j++;
      }
    }
  }

  template< typename T, template< typename > typename  S, typename Cmp = std::less< T > >
  void insert_sort(typename S< T >::container_t& cont, Cmp cmp = std::less< T >())
  {
    insert_sort< T, S >(cont, S< T >::begin(cont), S< T >::end(cont), cmp);
  }
}

#endif // INSERT_SORT_HPP
