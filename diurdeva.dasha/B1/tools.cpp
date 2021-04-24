#include "tools.hpp"
#include <ctime>

void diurdeva::fillRandom(double *array, size_t size)
{
  srand(time(NULL));
  for (size_t i = 0; i < size; i++) {
    array[i] = (rand() % 21) / 10.0 - 1;
  }
}

bool diurdeva::checkIsNumber(const char* string)
{
  for (size_t i = 0; i < strlen(string); i++)
  {
    if ((string[i] < '0') || (string[i] > '9'))
    {
      return false;
    }
  }
  return true;
}
