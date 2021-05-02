#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <iostream>
#include <functional>

template< typename T >
std::function< bool(T, T) > getSortMode(const std::string& mode)
{
  if (mode != "ascending" && mode != "descending")
  {
    std::cerr << "Invalid sorting mode";
    std::exit(1);
  }
  if (mode == "ascending")
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

#endif
