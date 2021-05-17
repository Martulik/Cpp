#include "tools.hpp"

#include <istream>
#include <cstdlib>
#include <stdexcept>

namespace lab = savchuk;

int lab::readKey(std::istream& is, char delim)
{
  int key;
  if (is)
  {
    is >> std::ws >> key;
    if (!is.eof())
    {
      if (is.get() != delim || is.fail())
      {
        is.setstate(std::ios::failbit);
        return key;
      }
      if (std::abs(key) > 5)
      {
        throw std::invalid_argument("invalid key");
      }
    }
  }
  return key;
}

std::string lab::readString(std::istream& is)
{
  std::string str;
  if (is)
  {
    if (!getline(is, str) || str.empty())
    {
      throw std::runtime_error("input error");
    }
  }
  return str;
}
