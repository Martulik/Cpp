#include "functions.hpp"
#include <iostream>
#include <algorithm>

bool lebedeva::isNumber(const std::string& str)
{
  bool bResult = false;
  if (str.length() >= 1)
  {
    std::string::const_iterator it = str.begin();
    if (str.length() > 1)
    {
      if ((*it == '+') || (*it == '-'))
      {
        it++;
      }
    }
    if (std::all_of(it, str.end(), ::isdigit))
    {
      bResult = true;
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
  std::for_each(data.begin(), data.end(),
    [&](DataStruct& src)
    {
      out << src;
    }
  );
}
