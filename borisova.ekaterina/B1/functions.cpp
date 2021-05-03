#include "functions.hpp"
#include <ctime>
#include <cstring>

void borisova::fillRandom(double* array, const int size)
{
  srand(time(0));
  for (int i = 0; i < size; i++)
  {
    int temp = (rand() % 201) - 100;
    array[i] = temp * 0.01;
  }
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
