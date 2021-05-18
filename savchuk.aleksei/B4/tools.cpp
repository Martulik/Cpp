#include "tools.hpp"

#include <istream>
#include <cstdlib>

namespace lab = savchuk;

int lab::readKey(std::istream& is, char delim)
{
  int key;
  if (is >> std::ws >> key)
  {
    if (is.get() != delim)
    {
      is.setstate(std::ios::failbit);
    }
    else if (std::abs(key) > 5)
    {
      is.setstate(std::ios::failbit);
    }
  }
  return key;
}

std::string lab::readString(std::istream& is)
{
  std::string str;
  if (is)
  {
    if (!getline(is >> std::ws, str) || str.empty())
    {
      is.setstate(std::ios::failbit);
    }
  }
  return str;
}
