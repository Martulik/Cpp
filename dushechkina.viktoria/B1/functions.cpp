#include "functions.hpp"


void dushechkina::fillRandom(double* array, int size)
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
      array[i] = (-1) * array[i];
    }
  }
}