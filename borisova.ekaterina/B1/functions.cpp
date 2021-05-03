#include "functions.hpp"
#include <cstring>

void borisova::fillRandom(double* array, const int size)
{
  for (int i = 0; i < size; i++)
  {
    array[i] = randomNumber();
  }
}

double borisova::randomNumber()
{
  int temp = (rand() % 2001) - 1000;
  return temp * 0.001;
}

bool borisova::checkNumber(const char* number)
{
  size_t i = 0;
  while (i < strlen(number))
  {
    if (!isdigit(number[i]))
    {
      std::cerr << "There isn't an integer number";
      return false;
    }
    i++;
  }
  return true;
}
