#include "data-struct.hpp"

#include <iostream>

std::istream& razukrantov::operator>>(std::istream& in, DataStruct& ds)
{
  std::string line;
  std::getline(in, line); 
}

std::ostream& razukrantov::operator<<(std::ostream& out, const DataStruct& ds)
{
  out << ds.key1 << "," << ds.key2 << "," << ds.str;
  return out;
}

bool razukrantov::operator<(const DataStruct& lhs, const DataStruct& rhs)
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
    return lhs.str.length() < rhs.str.length();
  }
}

int razukrantov::readKey(std::istream& in)
{
  std::string str;
  std::getline(in, str, ',');
  try
  {
    int key = std::atoi(str);
  }
  catch (std::exception& err)
  {
    in.setstate(std::ios::failbit);
    return 0;
  }
  if (key < -5 || key >5)
  {
    in.setstate(std::ios::failbit);
    return 0;
  }
  return key;
}
