#ifndef TOOLS_HPP
#define TOOLS_HPP
#include <iostream>

namespace murzakanov
{
  template< typename T >
  void print(const T& store, std::ostream& out)
  {
    using iter = typename T::const_iterator;
    iter it = store.begin();
    iter end = store.end();
    while (it != end)
    {
      out << *it << " ";
      it++;
    }
    std::cout << "\n";
  }

  void fillRandom(double* array, int size);
}
#endif
