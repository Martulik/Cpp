#include "tools.hpp"

#include <cstddef>
#include <stdexcept>
#include <vector>
#include <cctype>
#include <random>

namespace lab = savchuk;

size_t lab::convertToNumber(const std::string& str)
{
  size_t len = str.size();
  int num = 0;
  for (size_t i = 0; i < len; ++i)
  {
    if (isdigit(str[i]))
    {
      num *= 10;
      num += str[i] - '0';
    }
    else
    {
      throw std::runtime_error("invalid number format");
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
void lab::removeEvenNumbers(std::vector< int >& vec)
{
  using iterator = typename std::vector< int >::iterator;
  std::vector< int > tmp = vec;
  for (iterator it = tmp.begin(); it != tmp.end();)
  {
    if (*it % 2 == 0)
    {
      it = tmp.erase(it);
    }
    else
    {
      ++it;
    }
  }
  vec.swap(tmp);
}
void lab::addExtraNumbers(std::vector< int >& vec)
{
  using iterator = typename std::vector< int >::iterator;
  std::vector< int > tmp = vec;
  size_t count = 0;
  for (iterator it = tmp.begin(); it != tmp.end(); ++it)
  {
    if (*it % 3 == 0)
    {
      ++count;
    }
  }
  tmp.reserve(tmp.size() + 3 * count);
  for (iterator it = tmp.begin(); it != tmp.end();)
  {
    if (*it % 3 == 0)
    {
      it = tmp.insert(++it, { 1, 1, 1 });
    }
    else
    {
      ++it;
    }
  }
  vec.swap(tmp);
}
