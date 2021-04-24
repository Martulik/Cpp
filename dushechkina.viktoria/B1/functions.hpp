#ifndef B1_FUNCTIONS_HPP
#define B1_FUNCTIONS_HPP

#include <ctime>
#include <functional>
#include <iostream>
#include <stdexcept>
#include <string>

#include "strategy.hpp"

template<class T>
void print(T& container, const char* separator)
{
  for (auto i = container.begin(); i != container.end(); i++)
  {
    std::cout << *i << separator;
  }
}

template<class T>
void fillRandom(double* array, int size)
{
  if (array == nullptr)
  {
    throw std::invalid_argument("Array is nullptr");
  }
  for (int i = 0; i < size; i++)
  {
    array[i] = (rand() % 100) / 100.0;
    int sign = rand() % 10;
    if ((sign % 2 == 0) && (array[i] != 0))
    {
      array[i] = (-1)*array[i];
    }
  }
}

#endif
