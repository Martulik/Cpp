#ifndef B1_FUNCTIONS_HPP
#define B1_FUNCTIONS_HPP

#include <ctime>
#include <functional>
#include <iostream>
#include <stdexcept>
#include <string>

#include "strategy.hpp"

template<class T>
std::function<bool(const T, const T)> getSortingOrder(const char* order)
{
  std::string ascending = "ascending";
  std::string descending = "descending";
  if (order == nullptr)
  {
    throw std::invalid_argument("Sorting order is undefined");
  }
  if (order == ascending)
  {
    return std::less<const T>();
  }
  if (order == descending)
  {
    return std::greater<const T>();
  }
  else {
    throw std::invalid_argument("Sorting order is incorrect");
  }
}

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
  srand(time(NULL));
  for (int i = 0; i < size; i++) {
    array[i] = (rand() % 100) / 100.0;
    int sign = rand() % 10;
    if ((sign % 2 == 0) && (array[i] != 0))
    {
      array[i] = (-1)*array[i];
    }
  }
}

#endif