#include "tools.hpp"

#include <functional>
#include <random>
#include <ctime>

void murzakanov::fillRandom(double* array, int size)
{
  for (int i = 0; i < size; i++)
  {
    array[i] = static_cast< double >(rand()) / RAND_MAX * 2 - 1;
  }
}

bool murzakanov::checkIsNumber(const char* str)
{
  for (size_t i = 0; i < strlen(str); i++)
  {
    if (str[i] < '0' || str[i] > '9')
    {
      return false;
    }
  }
  return true;
}

bool murzakanov::checkForSpaces(const char* str)
{
  for (size_t i = 0; i < strlen(str); i++)
  {
    if (str[i] == ' ')
    {
      return true;
    }
  }
  return false;
}
