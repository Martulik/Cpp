#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <iostream>
#include <cstring>
#include <functional>

namespace ferapontov
{
  template< typename T >
  std::function< bool(T, T) > getSortMode(const char* mode)
  {
    if (strcmp(mode, "ascending") && strcmp(mode, "descending"))
    {
      std::cerr << "Invalid sorting mode";
      std::exit(1);
    }
    if (!strcmp(mode, "ascending"))
    {
      return std::greater< T >();
    }
    else
    {
      return std::less< T >();
    }
  }

  template< typename T>
  void print(const T& arr)
  {
    typedef typename T::const_iterator iter;
    iter it = arr.begin();
    iter end = arr.end();
    while(it != end)
    {
      std::cout << *it << ' ';
      it++;
    }
    std::cout << '\n';
  }

  void checkSpaces(const char* str);
  void checkNumber(const char* str);
}


#endif
