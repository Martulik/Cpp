#include "DataStruct.hpp"

#include <iostream>
#include <cmath>

namespace lab = shkurov;

std::istream& lab::operator>>(std::istream& in, lab::DataStruct& data)
{
  data.key1 = readKey(in);
  data.key2 = readKey(in);
  getline(in, data.str, '\n');

  if (in.eof())
  {
    return in;
  }
  else if ((in.fail() && !in.eof()) || (data.str.empty()))
  {
    throw std::logic_error("Error while reading.");
  }

  return in;
}

int lab::readKey(std::istream& in)
{
  std::string keyStr;
  std::getline(in >> std::ws, keyStr, ',');

  int key = 0;
  try
  {
    key = intConvert(keyStr);
  }
  catch (const std::exception& ex)
  {
    in.setstate(std::ios_base::failbit);
  }

  if (std::abs(key) > 5)
  {
    in.setstate(std::ios_base::failbit);
  }

  return key;
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

int lab::intConvert(const std::string& str)
{
  std::string::const_iterator it = str.cbegin();
  if (*it == '-' && str.size() > 1)
  {
    it++;
  }

  while (it != str.cend())
  {
    if (!std::isdigit(*it))
    {
      return 6;
    }
    it++;
  }

  return std::stoi(str);
}
