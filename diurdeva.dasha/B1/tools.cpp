#include "tools.hpp"
#include <ctime>
#include <cstring>
#include <cctype>

void diurdeva::fillRandom(double *array, size_t size)
{
  for (size_t i = 0; i < size; ++i) {
    array[i] = (rand() % 21) / 10.0 - 1;
  }
}

bool diurdeva::isNumber(const char* str)
{
  for (size_t i = 0; i < strlen(str); i++) {
    if (str[i] == '\n' || !isdigit(str[i])) {
      return false;
    }
  }
  return true;
}

