#include "data-struct.hpp"

#include <iostream>

#include "tools.hpp"

namespace lab = savchuk;

std::istream& lab::operator>>(std::istream& is, lab::DataStruct& ds)
{
  char delim = ',';
  int key1 = readKey(is, delim);
  int key2 = readKey(is, delim);
  std::string str = readString(is);
  if (is.fail() && !is.eof())
  {
    throw std::runtime_error("oops");
  }
  else
  {
    ds = { key1, key2, str };
  }
  return is;
}

std::ostream& lab::operator<<(std::ostream& os, const lab::DataStruct& ds)
{
  const char* delim = ", ";
  os << ds.key1 << delim << ds.key2 << delim << ds.str;
  return os;
}
