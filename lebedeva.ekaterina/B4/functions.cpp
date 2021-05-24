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

int lebedeva::isNegative(std::string& str)
{
  int result = 1;
  if (str.length() > 1)
  {
    if (str[0] == '-')
    {
      result = -1;
    }
  }
  return result;
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
