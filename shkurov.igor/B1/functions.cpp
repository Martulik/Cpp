#include "functions.hpp"

#include <cmath>
#include <ctype.h>

namespace lab = shkurov;

void lab::fillRandom(double *array, int size)
{
  for (int i = 0; i < size; i++)
  {
    array[i] = round((static_cast< double >(rand()) / RAND_MAX * 2 - 1) * 10) / 10;
  }
}

bool lab::containsSpaces(size_t argsCount, char* argv[])
{
  for (size_t i = 1; i < argsCount; i++)
  {
    if (std::string(argv[i]).find(' ') != std::string::npos)
    {
      return true;
    }
  }

  return false;
}

bool lab::isNumber(const std::string& str)
{
  for (size_t i = 0; i < str.size(); i++)
  {
    if (!std::isdigit(str[i]))
    {
      return false;
    }
  }
  return true;
}
