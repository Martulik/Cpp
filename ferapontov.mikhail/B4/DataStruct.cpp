#include "DataStruct.hpp"

#include <iostream>
#include <sstream>

std::istream& ferapontov::operator>>(std::istream& in, DataStruct& src)
{
  std::istream::sentry sentry(in);
  if (sentry)
  {
    char delim = ',';
    std::string line;
    std::getline(in, line);
    std::istringstream stream(line);

    int key1 = readNumber(stream, delim);
    int key2 = readNumber(stream, delim);

    if (std::abs(key1) > 5 || std::abs(key2) > 5)
    {
      in.setstate(std::ios::badbit);
    }

    std::string name;
    std::getline(stream, name);
    if(stream.fail())
    {
      in.setstate(std::ios::badbit);
    }
    else
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

int ferapontov::readNumber(std::istream& in, const char& delim)
{
  std::string number;
  std::getline(in, number, delim);
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
