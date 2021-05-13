#include <cstring>
#include <cctype>
#include <stdexcept>
#include "functions.hpp"

bool lebedeva::isNumber(const char* num)
{
  for (size_t i = 0; i < strlen(num); i++)
  {
    if (!std::isdigit(num[i]))
    {
      throw std::invalid_argument("Not a number");
    }
    i++;
  }
  return true;
}

void lebedeva::checkNumOfArgs(int argc, int expected)
{
  if (argc != expected)
  {
    throw std::invalid_argument("Invalid number of arguments");
  }
}

void lebedeva::fillRandom(double* array, int size)
{
  if (size <= 0)
  {
    throw std::invalid_argument("Invalid array size");
  }
  for (size_t i = 0; i < sizeof(array); i++)
  {
    array[i] = static_cast<double>(rand()) / RAND_MAX * 2 - 1;
  }
}
