#include "tools.hpp"
#include <ctime>

void diurdeva::fillRandom(double *array, size_t size)
{
  srand(time(NULL));
  for (size_t i = 0; i < size; i++) {
    array[i] = (rand() % 21) / 10.0 - 1;
  }
}

bool diurdeva::checkIsNumber(const std::string &str)
{
  for (int i = 0; i < int(str.length()); i++) {
    if (str[i] < '0' || str[i] > '9') {
      return false;
    }
  }
  return true;
}
