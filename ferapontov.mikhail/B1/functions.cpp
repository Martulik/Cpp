#include "functions.hpp"

std::default_random_engine& getRandomEngine()
{
  static std::default_random_engine randomEngine(std::random_device{}());
  return randomEngine;
}

void ferapontov::fillRandom(double* array, int size)
{
  std::uniform_int_distribution< > dist(-10, 10);
  for (int i = 0; i < size; i++) {
    array[i] = dist(getRandomEngine()) / 10.0;
  }
}

void ferapontov::checkSpaces(const char* str)
{
  for (size_t i = 0; i < strlen(str); i++)
  {
    if (str[i] == ' ')
    {
      std::cerr << "Argument with spaces";
      std::exit(1);
    }
  }
}

void ferapontov::checkNumber(const char* str)
{
  for (size_t i = 0; i < strlen(str); i++)
  {
    if(!isdigit(str[i]))
    {
      std::cerr << "Argument is not a number";
      std::exit(1);
    }
  }
}
