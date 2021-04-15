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

bool iva::checkIsNumber(const std::string& str)
{
  for (int i = 0; i < int(str.length()); i++)
  {
    if (str[i] < '0' || str[i] > '9')
    {
      return false;
    }
  }
  return true;
}

bool iva::checkForSpaces(const std::string& str)
{
  return (str.find(' ') != std::string::npos);
}
