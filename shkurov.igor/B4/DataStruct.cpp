#include "DataStruct.hpp"

#include <iostream>
#include <cmath>

namespace lab = shkurov;

std::istream& lab::operator>>(std::istream& in, lab::DataStruct& data)
{
  data.key1 = readKey(in);
  data.key2 = readKey(in);
  getline(in, data.str);

  if (in.fail())
  {
    throw std::logic_error("Error while reading.");
  }

  return in;
}

int lab::readKey(std::istream& in)
{
  std::string keyStr;
  std::getline(in, keyStr, ',');

  int key;
  try
  {
    key = std::stoi(keyStr);
  }
  catch (const std::exception& ex)
  {
    in.setstate(std::ios_base::failbit);
  }

  if (std::abs(key) > 5)
  {
    in.setstate(std::ios_base::failbit);
  }

  return (in.good() ? key : 0);
}

bool lab::compare(const lab::DataStruct& lhs, const lab::DataStruct& rhs)
{
  if (lhs.key1 != rhs.key1)
  {
    return lhs.key1 < rhs.key1;
  }
  else if (lhs.key2 != rhs.key2)
  {
    return lhs.key2 < rhs.key2;
  }
  return lhs.str.length() < rhs.str.length();
}

std::ostream& lab::operator<<(std::ostream& out, const lab::DataStruct& data)
{
  out << data.key1 << ", " << data.key2 << ", " << data.str << '\n';
  return out;
}
