#include "data-struct.hpp"

#include <iostream>

bool pochernin::operator<(const DataStruct& lhs, const DataStruct& rhs)
{
  if (lhs.key1 != rhs.key1)
  {
    return lhs.key1 < rhs.key1;
  }
  else if (lhs.key2 != rhs.key2)
  {
    return lhs.key2 < rhs.key2;
  }
  else
  {
    return lhs.str < rhs.str;
  }
}

std::ostream& pochernin::operator<<(std::ostream& out, const DataStruct& dataStruct)
{
  out << dataStruct.key1 << ", " << dataStruct.key2 << ", " << dataStruct.str;
  return out;
}