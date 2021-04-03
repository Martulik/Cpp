#include "tools.hpp"

#include <cstdlib>
#include <ctime>

void fillRandom(double *array, int size)
{
  srand(time(NULL));
  for (int i = 0; i < size; ++i) {
    array[i] = 0.01 * ((rand() % 101) - (rand() % 101));
  }
}
