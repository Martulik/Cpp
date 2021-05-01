#include "functions.hpp"
#include <cstdlib>

namespace iva = ivanova;

void iva::fillRandom(double* array, int size)
{
  if (size < 0)
  {
    std::cerr << "Size must be nonzero";
    exit (1);
  }
  for (int i = 0; i < size; i++)
  {
    array[i] = double(rand()) / RAND_MAX * 2 - 1;
  }
}

bool iva::checkIsNumber(const char* str)
{
  for (int i = 0; i < int(strlen(str)); i++)
  {
    if (!isdigit(str[i]))
    {
      return false;
    }
  }
  return true;
}

int iva::charToInt(char* string)
{
  int result = 0;
  for (size_t i = 0; i < strlen(string); i++)
  {
    if ((string[i] == '\n') || (!isdigit(string[i])))
    {
      return {};
    }
  }
  result = std::atoi(string);
  return result;
}
