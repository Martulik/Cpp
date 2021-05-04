#include "tools.hpp"

void ezerinia::fillRandom(double *array, int size)
{
  for (int i = 0; i < size; ++i) {
    array[i] = 0.01 * ((rand() % 101) - (rand() % 101));
  }
}
