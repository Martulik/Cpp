#include "tools.hpp"

#include <cstddef>
#include <stdexcept>

namespace lab = savchuk;

size_t lab::convertToNumber(const std::string& str)
{
  size_t len = str.size();
  int num = 0;
  for (size_t i = 0; i < len; ++i)
  {
    if ('0' <= str[i] && str[i] <= '9')
    {
      num *= 10;
      num += str[i] - '0';
    }
    else
    {
      throw std::invalid_argument("invalid number format");
    }
  }
  return num;
}
void lab::fillRandom(double* array, size_t size)
{
  std::random_device rd;
  std::uniform_int_distribution<> dist(-10, 10);
  for (size_t i = 0; i < size; ++i)
  {
    array[i] = dist(rd) / 10.0;
  }
}