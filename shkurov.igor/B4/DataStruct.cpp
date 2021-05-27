#include "DataStruct.hpp"

#include <iostream>
#include <cmath>
#include <limits>
#include <algorithm>

namespace lab = shkurov;

std::istream& lab::operator>>(std::istream& in, lab::DataStruct& data)
{
  in >> std::ws;
  if (in.eof())
  {
    in.ignore(std::numeric_limits< std::streamsize >::max());
    return in;
  }

  std::string str;
  getline(in, str, '\n');

  data.key1 = readKey(str);
  data.key2 = readKey(str);

  if (str.empty())
  {
    throw std::invalid_argument("Incorrect input format.");
  }
  data.str = str;

  return in;
}

int lab::readKey(std::string& str)
{
  std::string::const_iterator it = str.cbegin();

  while (it != str.cend())
  {
    if (*it == ',')
    {
      break;
    }
    it++;
  }

  if (it == str.cend())
  {
    throw std::invalid_argument("Incorrect input format.");
  }

  std::string key(str.cbegin(), it);
  str.erase(str.cbegin(), it + 1);

  return abs(stoi(key)) <= 5 ? stoi(key) : throw std::out_of_range("Values out of valid range.");
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
  out << data.key1 << "," << data.key2 << "," << data.str << '\n';
  return out;
}
