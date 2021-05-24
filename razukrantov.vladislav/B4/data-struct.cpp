#include "data-struct.hpp"

#include <iostream>
#include <string>
#include <sstream>

std::istream& razukrantov::operator>>(std::istream& in, DataStruct& ds)
{
  std::string line;
  std::getline(in, line);
  int key1 = readKey(line, in);
  int key2 = readKey(line, in);
  std::string::iterator iterator = line.begin();
  std::string str;
  while (iterator != line.end())
  {
    str += *iterator;
    ++iterator;
  }
  if (str.empty())
  {
    in.setstate(std::ios::failbit);
  }
  if (!in.fail())
  {
    ds = { key1, key2, str };
  }
  return in;
}

std::ostream& razukrantov::operator<<(std::ostream& out, const DataStruct& ds)
{
  out << ds.key1 << ", " << ds.key2 << ", " << ds.str;
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

int razukrantov::readKey(std::string& line, std::istream& in)
{
  std::string str;
  std::string::iterator iterator = line.begin();
  while (*iterator != ',')
  {
    if (iterator == line.end())
    {
      in.setstate(std::ios::failbit);
      return 0;
    }
    str += *iterator;
    line.erase(iterator);
  }
  line.erase(0, 1);
  int key = 0;
  try
  {
    key = std::stoi(str);
  }
  catch (std::exception& err)
  {
    in.setstate(std::ios::failbit);
    return 0;
  }
  if (key < -5 || key > 5)
  {
    in.setstate(std::ios::failbit);
    return 0;
  }
  return key;
}
