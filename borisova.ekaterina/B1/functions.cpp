#include "functions.hpp"
#include <cstring>

void borisova::fillRandom(double* array, const int size)
{
  for (int i = 0; i < size; i++)
  {
    array[i] = randomNumber() * 0.001;
  }
}

int borisova::randomNumber()
{
  return(rand() % 2001) - 1000;
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
