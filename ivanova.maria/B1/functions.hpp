#ifndef B1_FUNCTIONS_H
#define B1_FUNCTIONS_H

#include <iostream>
#include <vector>
#include <forward_list>
#include <cstring>
#include <fstream>

namespace ivanova
{
  void fillRandom(double* array, int size);

  template< typename T > struct strategyBrackets
  {
    using cont = std::vector< T >;
    using iter = size_t;
    static iter begin(cont &)
    {
      return 0;
    }

    static iter end(cont &vector)
    {
      return vector.size();
    }

    static T &get(cont &vector,iter i)
    {
      return vector[i];
    }
  };

  template< typename T > struct strategyAt
  {
    using cont = std::vector< T >;
    using iter = size_t;
    static iter begin(cont &)
    {
      return 0;
    }

    static iter end(cont &vector)
    {
      return vector.size();
    }

    static T &get(cont &vector, iter i)
    {
      return vector.at(i);
    }
  };

  template< typename T > struct strategyList
  {
    using cont = std::forward_list< T >;
    using iter = typename std::forward_list< T >::iterator;
    static iter begin(cont &list)
    {
      return list.begin();
    }

    static iter end(cont &list)
    {
      return list.end();
    }

    static T &get(cont &, iter i)
    {
      return *i;
    }
  };

template< typename T>
void sort(typename T::cont &cont, typename T::iter begin, typename T::iter end, const char *method)
{
  if (strcmp(method, "ascending") && strcmp(method, "discending"))
  {
    throw std::invalid_argument("Incorrect sort order!");
  }
  bool ascending = false;
  if (!strcmp(method, "ascending"))
  {
    ascending = true;
  }
  using iter = typename T::iter;
  for (iter it1 = begin; it1 != end; ++it1)
  {
    iter it2 = it1;
    for (it2++; it2 != end; ++it2)
    {
      if (ascending)
      {
        if (T::get(cont, it2) < T::get(cont, it1))
        {
          std::swap(T::get(cont, it2), T::get(cont, it1));
        }
      }
      else if (T::get(cont, it2) > T::get(cont, it1))
      {
        std::swap(T::get(cont, it2), T::get(cont, it1));
      }
    }
  }
}

template< typename T > void print(const T &src, std::ostream &out)
{
  typedef typename T::const_iterator Iter;
  Iter it = src.begin();
  while (it != src.end())
  {
    out << *it << " ";
    it++;
  }
  out << "\n";
}

template< typename T > void sortAndPrint(typename T::cont &cont, const char *method)
{
  sort< T >(cont, T::begin(cont), T::end(cont), method);
  print(cont, std::cout);
}
}
#endif
