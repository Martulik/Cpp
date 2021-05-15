#include "functions.hpp"

#include <cctype>
#include <cmath>

bool pyatizbyantsev::checkSpaces(const char* str)
{
  if (strchr(str, ' '))
  {
    return true;
  }
  return false;
}

bool pyatizbyantsev::checkNumber(const char* str)
{
  for (size_t i = 0; str[i] != '\0'; i++)
  {
    if (!std::isdigit(str[i]))
    {
      return false;
    }
  }
  return true;
}

void pyatizbyantsev::fillRandom(double *array, int size)
{
  for (int i = 0; i < size; i++)
  {
    array[i] = trunc((static_cast< double >(rand()) / RAND_MAX * 2 - 1) * 10) / 10;
  }
}
