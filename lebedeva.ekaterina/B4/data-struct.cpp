#include "data-struct.hpp"
#include <iostream>
#include <vector>
#include <sstream>
#include "functions.hpp"

std::ostream& lebedeva::operator<<(std::ostream& out, const DataStruct& data)
{
  out << data.key1 << ',' << data.key2 << ',' << data.str << '\n';
  return out;
}

std::istream& lebedeva::operator>>(std::istream& in, DataStruct& data)
{
  std::string inStr;
  std::getline(in, inStr);
  if (!in.fail())
  {
    std::string key1, key2;
    DataStruct temp;
    const char delimiter = ',';
    std::istringstream input(inStr);
    std::getline(input >> std::ws, key1, delimiter);
    if (!input.fail() && !key1.empty() && isNumber(key1))
    {
      temp.key1 = std::stoi(key1);
      if (isAcceplable(temp.key1))
      {
        std::getline(input >> std::ws, key2, delimiter);
        if (!input.fail() && !key2.empty() && isNumber(key2))
        {
          temp.key2 = std::stoi(key2);
          if (isAcceplable(temp.key2))
          {
            std::getline(input, data.str);
            if (!input.fail() && !data.str.empty())
            {
              data.key1 = temp.key1;
              data.key2 = temp.key2;
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
