#include "functions.hpp"
#include <ctime>

void borisova::fillRandom(double* array, const int size)
{
  srand(time(0));
  for (int i = 0; i < size; i++)
  {
    array[i] = (double(rand() % 201) - 100)*0.01;
  }
}

bool borisova::checkNumber(const std::string& number)
{
  for (size_t i = 0; i < number.length(); i++)
  {
    if (!(number[i] >= '0' && number[i] <= '9'))
    {
      std::cerr << "There isn't an integer number";
      return false;
    }
  }
  return true;
}

int borisova::toInt(const std::string& number)
{
  int temp = -1;
  if (borisova::checkNumber(number))
  {
    temp = int(number[0] - '0');
    for (size_t i = 1; i < number.length(); i++)
    {
      temp *= 10;
      temp += int(number[i] - '0');
    }
  }
  return temp;
}
