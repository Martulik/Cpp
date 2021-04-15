#include "functions.hpp"

#include <cstdlib>

void ivanova::fillRandom(double* array, int size)
{
  for (int i = 0; i < size; i++)
  {
    array[i] = double(rand()) / RAND_MAX * 2 - 1;
  }
}
