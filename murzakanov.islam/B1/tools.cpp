#include "tools.hpp"

#include <random>
#include <ctime>

void murzakanov::fillRandom(double* array, int size)
{
  srand(time(0));
  for (int i = 0; i < size; i++)
  {
    array[i] = double(rand()) / RAND_MAX * 2 - 1;
  }
}
