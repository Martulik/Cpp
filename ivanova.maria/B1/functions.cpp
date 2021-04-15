#include "functions.hpp"
#include <cstdlib>

namespace iva = ivanova;

void iva::fillRandom(double* array, int size)
{
  if (size < 0)
  {
    throw std::invalid_argument("Size must be nonzero");
  }
  for (int i = 0; i < size; i++)
  {
    array[i] = double(rand()) / RAND_MAX * 2 - 1;
  }
}
