#include "tools.hpp"

size_t murzakanov::getValue(const size_t num)
{
  if (num == 1)
  {
    return 1;
  }
  return num * getValue(num - 1);
}
