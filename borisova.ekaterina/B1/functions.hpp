#ifndef FINCTIONS_HPP
#define FINCTIONS_HPP

#include <iostream>
#include <functional>
#include "strategies.hpp"

namespace borisova
{
  void fillRandom(double* array, int size);
  bool checkNumber(const std::string& number);
  int toInt(const std::string& number);

  template< typename T >
  std::function< bool(T, T) > sortMode(const std::string& mode)
  {
    const std::string ascending = "ascending";
    const std::string descending = "descending";
    if (mode == ascending)
    {
      return std::greater< T >();
    }
    else if (mode == descending)
    {
      return std::less< T >();
    }
    return nullptr;
  }

  template < typename C, typename T >
  int sort(typename C::container & src, T sortMode)
  {
    using itr = typename C::iterator;
    if (sortMode == nullptr)
    {
      std::cerr << "\nWrong mode of sort\n";
      return 1;
    }
    itr end = C::end(src);
    for (itr i = C::begin(src); i != end; i++)
    {
      for (itr j = i; j != end; j++)
      {
        if (sortMode(C::get(src, i), C::get(src, j)))
        {
          std::swap(C::get(src, j), C::get(src, i));
        }
      }
    }
    return 0;
  }

  template< typename T >
  void print(const T& src, std::ostream& out)
  {
    using itr = typename T::const_iterator;
    itr iter = begin(src);
    while (iter != end(src))
    {
      out << *iter << " ";
      iter++;
    }
    out << "\n";
  }
}

#endif
