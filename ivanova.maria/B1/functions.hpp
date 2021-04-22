#ifndef B1_FUNCTIONS_H
#define B1_FUNCTIONS_H

#include <iostream>
#include <vector>
#include <forward_list>
#include <cstring>
#include <fstream>
#include <functional>

namespace ivanova
{
  void fillRandom(double* array, int size);
  bool checkIsNumber(const std::string& str);
  int charToInt(char* string);

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

  template< typename T, typename S>
  void sort(typename T::cont &cont, const S sortMode)
  {
    if (sortMode == nullptr)
    {
      std::cerr << "Wrong sort mode";
      exit(1);
    }
    using iter = typename T::iter;
    for (iter it1 = T::begin(cont); it1 != T::end(cont); ++it1)
    {
      iter it2 = it1;
      for (it2++; it2 != T::end(cont); ++it2)
      {
        if (sortMode(T::get(cont, it2), T::get(cont, it1)))
        {
          std::swap(T::get(cont, it2), T::get(cont, it1));
        }
      }
    }
  }

  template< typename T > void print(const T &src, std::ostream &out)
  {
    using iter = typename T::const_iterator;
    iter it = src.begin();
    iter end = src.end();
    while (it != end)
    {
      out << *it << " ";
      it++;
    }
    out << "\n";
  }

  template< typename T, typename S > void sortAndPrint(typename T::cont &cont, S sortMode)
  {
    sort< T, S >(cont, sortMode);
    print(cont, std::cout);
  }

  template< typename T >
  std::function< bool(T, T) > getSortMode(const char *method)
  {
    if (!strcmp(method, "ascending"))
    {
      return std::less< T >();
    }
    else if (!strcmp(method, "descending"))
    {
      return std::greater< T >();
    }
    return nullptr;
  }
}
#endif
