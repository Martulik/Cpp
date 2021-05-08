#include "functions.hpp"

#include <ctime>

void razukrantov::fillRandom(double* array, int size)
{
  if (size <= 0)
  {
    throw(std::invalid_argument("Incorrect size"));
  }
  for (int i = 0; i < size; i++)
  {
    array[i] = (static_cast<double>(rand()) / RAND_MAX) * 2 - 1;
  }
}

bool razukrantov::isNumber(const char* str)
{
  for (size_t i = 0; i < strlen(str); i++)
  {
    if (!std::isdigit(str[i]))
    {
      return false;
    }
  }
  return true;
}

bool razukrantov::checkSpaces(const char* str)
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
