#ifndef INSERT_SORT_HPP
#define INSERT_SORT_HPP

#include <utility>

namespace doroshin {
  template< template < typename > typename S, typename T >
  void insert_sort(typename S<T>::container_t cont, typename S<T>::iterator_t begin, typename S<T>::iterator_t end)
  {
    using std::swap; // lookup for both std::swap and doroshin::swap
    using It = typename S<T>::iterator_t;
    for(It i = begin; i != end; ++i) {
      for(It j = i; j > begin; --j) {
        T& lhs = S<T>::get(cont, j - 1);
        T& rhs = S<T>::get(cont, j);
        if(lhs < rhs)
          break;
        swap(S<T>::get(cont, j));
      }
    }
  }
}

#endif // INSERT_SORT_HPP
