#include "DataStruct.hpp"

#include <iostream>
#include <sstream>

std::istream& ferapontov::operator>>(std::istream& in, DataStruct& src)
{
  std::istream::sentry sentry(in);
  if (sentry)
  {
    std::string line;
    char delim = ',';
    std::getline(in, line);
    int key1 = readNumber(line, delim, in);
    int key2 = readNumber(line, delim, in);

    if (std::abs(key1) > 5 || std::abs(key2) > 5)
    {
      in.setstate(std::ios::badbit);
    }

    std::string name;
    std::string::iterator it = line.begin();
    while (it != line.end())
    {
      name += *it;
      ++it;
    }
    if (name.empty())
    {
      in.setstate(std::ios::badbit);
    }
    if (!in.fail())
    {
      src = {key1, key2, name};
    }
  }
  return in;
}

std::ostream& ferapontov::operator<<(std::ostream& out, const DataStruct& src)
{
  std::ostream::sentry sentry(out);
  if (sentry)
  {
    return out << src.key1 << ", " << src.key2 << ", " << src.str << '\n';
  }
  return out;
}

bool ferapontov::operator<(const DataStruct& lhs, const DataStruct& rhs)
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
    return lhs.str.size() < rhs.str.size();
  }
}

bool ferapontov::operator==(const DataStruct& lhs, const DataStruct& rhs)
{
  return lhs.key1 == rhs.key1 && lhs.key2 == rhs.key2 && lhs.str == rhs.str;
}

int ferapontov::readNumber(std::string& line, const char& delim, std::istream& in)
{
  std::string number;
  std::string::iterator it = line.begin();
  while (*it != delim)
  {
    if (it == line.end())
    {
      in.setstate(std::ios::badbit);
      return 0;
    }
    number += *it;
    line.erase(it);
  }
  line.erase(0, 1);
  try
  {
    int num = std::stoi(number);
    return num;
  }
  catch(const std::exception& e)
  {
    in.setstate(std::ios::badbit);
    return 0;
  }
}
