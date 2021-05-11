#ifndef TOOLS_HPP
#define TOOLS_HPP

#include <forward_list>
#include <vector>
#include <iostream>

namespace ezerinia {
  void fillRandom(double *array, int size);

  template< typename T >
  struct indexVec {
    using container_t = std::vector< T >;
    using iter_t = size_t;

    static iter_t begin(container_t &)
    {
      return 0;
    }

    static iter_t end(container_t &vec)
    {
      return vec.size();
    }

    static T &get(container_t &vec, iter_t index)
    {
      return vec[index];
    }
  };

  template< typename T >
  struct atVec {
    using container_t = std::vector< T >;
    using iter_t = size_t;

    static iter_t begin(container_t &)
    {
      return 0;
    }

    static iter_t end(container_t &vec)
    {
      return vec.size();
    }

    static T &get(container_t &vec, iter_t index)
    {
      return vec.at(index);
    }
  };

  template< typename T >
  struct iteratorList {
    using container_t = std::forward_list< T >;
    using iter_t = typename std::forward_list< T >::iterator;

    static iter_t begin(container_t &list)
    {
      return list.begin();
    }

    static iter_t end(container_t &list)
    {
      return list.end();
    }

    static T &get(container_t &, iter_t it)
    {
      return *it;
    }
  };

  template< typename T, typename C >
  void sort(typename T::container_t &cont, typename T::iter_t begin, typename T::iter_t end, C sort_mode)
  {
    using iter = typename T::iter_t;
    for (iter it1 = begin; it1 != end; ++it1) {
      iter it2 = it1;
      for (it2++; it2 != end; ++it2) {
        if (sort_mode(T::get(cont, it2), T::get(cont, it1))) {
          std::swap(T::get(cont, it2), T::get(cont, it1));
        }
      }
    }
  }

  template< typename T >
  void print(const T &src, std::ostream &out)
  {
    typedef typename T::const_iterator Iter;
    Iter it = src.begin();
    while (it != src.end()) {
      out << *it << " ";
      it++;
    }
    out << "\n";
  }

  template< typename T, typename C >
  void sortAndPrint(typename T::container_t &cont, C cmp, std::ostream &out)
  {
    sort< T, C >(cont, T::begin(cont), T::end(cont), cmp);
    print(cont, out);
  }

}
#endif
