#include "data-struct.hpp"
#include <iostream>

std::ostream& lebedeva::operator<<(std::ostream& out, const DataStruct& data)
{
  out << data.key1 << ',' << data.key2 << ',' << data.str << '\n';
  return out;
}

bool lebedeva::operator<(const DataStruct& lhs, const DataStruct& rhs)
{
  bool bResult = false;
  if (lhs.key1 < rhs.key1)
  {
    bResult = true;
  }
  else if (lhs.key1 == rhs.key1)
  {
    if (lhs.key2 < rhs.key2)
    {
      bResult = true;
    }
    else if (lhs.key2 == rhs.key2)
    {
      if (lhs.str.length() < rhs.str.length())
      {
        bResult = true;
      }
    }
  }
  return bResult;
}
