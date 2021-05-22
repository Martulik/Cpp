#include "data-struct.hpp"
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <cmath>

namespace poz = pozdnyakov;

std::ostream& poz::operator<<(std::ostream& out, const poz::DataStruct& obj)
{
  out << obj.key1 << ',' << obj.key2  << ',' << obj.str;
  return out;
}

std::istream& poz::operator>>(std::istream& in, poz::DataStruct& obj)
{
  std::istream::sentry sentry(in);
  if (sentry)
  {
    try
    {
      std::string buf;
      std::getline(in, buf);
      obj.key1 = poz::extractKey(buf);
      obj.key2 = poz::extractKey(buf);
      obj.str = buf;
    }
    catch (std::exception& exc)
    {
      std::cerr << exc.what() << '\n';
      in.setstate(std::ios::failbit);
    }
  }
  return in;
}

int poz::extractKey(std::string& str)
{
  size_t comma = str.find(',');
  if (comma == std::string::npos)
  {
    throw std::invalid_argument("Invalid input");
  }
  std::string buf = str.substr(0, comma);
  int key;
  if (std::abs(key = std::stoi(buf)) > 5)
  {
    throw std::invalid_argument("Invalid input");
  }
  str = str.substr(comma + 1, str.length() - comma);
  return key;
}

bool poz::comparator(const poz::DataStruct& s1, const poz::DataStruct& s2)
{
  if (s1.key1 < s2.key1)
  {
    return true;
  }
  else if (s1.key1 == s2.key1)
  {
    if (s1.key2 < s2.key2)
    {
      return true;
    }
    else if (s1.key2 == s2.key2)
    {
      return s1.str.length() < s2.str.length();
    }
  }
  return false;
}
