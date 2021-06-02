#include "data-struct.hpp"
#include <iostream>
#include <vector>
#include <sstream>
#include "functions.hpp"

std::ostream& lebedeva::operator<<(std::ostream& out, const DataStruct& data)
{
  out << data.key1 << ',' << data.key2 << ',' << data.str;
  return out;
}

std::istream& lebedeva::operator>>(std::istream& in, DataStruct& data)
{
  std::string inStr;
  std::getline(in, inStr);
  if (!in.fail())
  {
    std::string key1, key2;
    const char delimiter = ',';
    std::istringstream input(inStr);
    std::getline(input >> std::ws, key1, delimiter);
    if (!input.fail() && !key1.empty() && isNumber(key1))
    {
      data.key1 = std::stoi(key1);
      std::getline(input >> std::ws, key2, delimiter);
      if (!input.fail() && !key2.empty() && isNumber(key2))
      {
        data.key2 = std::stoi(key2);
        std::getline(input >> std::ws, data.str);
        if (input.fail() || !isAcceplable(data.key1) || !isAcceplable(data.key2))
        {
          in.setstate(std::ios::failbit);
        }
      }
      else
      {
        in.setstate(std::ios::failbit);
      }
    }
    else
    {
      in.setstate(std::ios::failbit);
    }
  }
  else
  {
    in.setstate(std::ios::failbit);
  }
  return in;
}

bool lebedeva::operator<(const DataStruct& lhs, const DataStruct& rhs)
{
  if (lhs.key1 == rhs.key1)
  {
    if (lhs.key2 == rhs.key2)
    {
      return (lhs.str.length() < rhs.str.length());
    }
    else
    {
      return (lhs.key2 < rhs.key2);
    }
  }
  else
  {
    return (lhs.key1 < rhs.key1);
  }
}
