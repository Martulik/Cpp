#include "functions.hpp"

#include <cmath>
#include <cctype>

namespace lab = shkurov;

void lab::fillRandom(double *array, int size)
{
  for (int i = 0; i < size; i++)
  {
    array[i] = round((static_cast< double >(rand()) / RAND_MAX * 2 - 1) * 10) / 10;
  }
}

bool lab::containsSpaces(const char* str)
{
  if (strchr(str, ' '))
  {
    return true;
  }

  return false;
}

bool lab::isNumber(const char* str)
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
