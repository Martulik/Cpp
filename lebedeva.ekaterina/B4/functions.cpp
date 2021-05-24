#include "functions.hpp"

bool lebedeva::isNumber(std::string& str)
{
  bool bResult = true;
  size_t iter = 0;
  if (str[0] == '+' || str[0] == '-')
  {
    iter++;
  }
  for (size_t i = iter; i < str.length(); i++)
  {
    if (!std::isdigit(str[i]))
    {
      bResult = false;
      break;
    }
  }
  return bResult;
}

bool lebedeva::isAcceplable(int key)
{
  bool bResult = false;
  if ((key > -6) && (key < 6))
  {
    bResult = true;
  }
  return bResult;
}
