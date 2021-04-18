#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <iostream>

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

#endif
