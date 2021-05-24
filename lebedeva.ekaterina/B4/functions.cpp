#include "functions.hpp"
#include <iostream>

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

void lebedeva::print(std::vector< DataStruct > data, std::ostream& out)
{
  for (size_t i = 0; i < data.size(); i++)
  {
    out << data[i];
  }
}
