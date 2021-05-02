#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <iostream>
#include <cstring>
#include <functional>
#include <random>

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
      return std::less< T >();
    }
    else
    {
      return std::greater< T >();
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

  template< typename T>
  void fillRandom(T& src, std::random_device& rd)
  {
    std::uniform_int_distribution< > dist(-10, 10);
    for (size_t i = 0; i < src.size(); i++)
    {
      src[i] = dist(rd) / 10.0;
    }
  }
  void checkSpaces(const char* str);
  void checkNumber(const char* str);
}


#endif
