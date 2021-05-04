#ifndef B1_FUNCTIONS_HPP
#define B1_FUNCTIONS_HPP

#include <iostream>
#include <stdexcept>

#include "strategy.hpp"
namespace dushechkina
{
  void fillRandom(double* array, int size);

  template< class T >
  void print(T& container, const char* separator)
  {
    for (auto i = container.begin(); i != container.end(); i++)
    {
      std::cout << *i << separator;
    }
  }
}

#endif
