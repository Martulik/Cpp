#include "tools.hpp"

#include <cstddef>

namespace lab = savchuk;

int lab::convertToNumber(const std::string& str)
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
      return -1;
    }
  }
  return num;
}