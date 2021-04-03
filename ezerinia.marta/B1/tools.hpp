#ifndef TOOLS_HPP
#define TOOLS_HPP

#include <iterator>
#include <list>
#include <iostream>

void fillRandom(double *array, int size);

namespace ezerinia {
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
    using container_t = std::list< T >;
    using iter_t = typename std::list< T >::iterator;

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

  template< typename S >
  void sort(typename S::container_t &cont, typename S::iter_t begin, typename S::iter_t end, int mode)
  {
    if (mode == 0 || mode == 1) {
      using iter = typename S::iter_t;
      for (iter it1 = begin; it1 != end; ++it1) {
        iter it2 = it1;
        for (it2++; it2 != end; ++it2) {
          if (((S::get(cont, it2) > S::get(cont, it1)) && mode) ||
              ((S::get(cont, it2) < S::get(cont, it1)) && (!mode))) {
            std::swap(S::get(cont, it2), S::get(cont, it1));
          }
        }
      }
    } else {
      std::cerr << "Wrong sort mode";
    }
  }

  template< typename T >
  void print(const T &src, std::ostream &out)
  {
    auto it = src.begin();
    while (it != src.end()) {
      out << *it << " ";
      it++;
    }
    out << "\n";
  }
}

#endif
