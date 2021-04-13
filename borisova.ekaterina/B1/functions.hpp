#ifndef FINCTIONS_HPP
#define FINCTIONS_HPP

#include <iostream>
#include "strategies.hpp"

namespace borisova
{
  void fillRandom(double* array, int size);
  bool checkNumber(const std::string& number);
  int toInt(const std::string& number);

  template < typename C >
  int sort(typename C::container & src, const std::string & mode)
  {
    using itr = typename C::iterator;
    bool value = 0;
    if (mode == "ascending")
    {
      value = true;
    }
    else if (mode == "descending")
    {
      value = false;
    }
    else
    {
      std::cerr << "Wrong mode\n";
      return 1;
    }

    itr end = C::end(src);
    for (itr i = C::begin(src); i != end; i++)
    {
      for (itr j = i; j != end; j++)
      {
        if ((C::get(src, i) <= C::get(src, j)) != value)
        {
          std::swap(C::get(src, i), C::get(src, j));
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
