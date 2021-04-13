#include "functions.hpp"
#include <ctime>

void borisova::fillRandom(double* array, const int size)
{
  srand(time(0));
  for (int i = 0; i < size; i++)
  {
    array[i] = (double(rand() % 201) - 100)*0.01;
  }
}
