#include "shape.hpp"

#include <iterator>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <cstddef>
#include <string>

namespace lab = savchuk;

std::istream& lab::operator>>(std::istream& is, Shape& shape)
{
  std::istream::sentry sentry(is);
  if (sentry)
  {
    std::string buffer;
    size_t size = 0u;
    Shape temp;
    if (getline(is >> std::ws, buffer))
    {
      std::istringstream ss(buffer);
      ss >> size;
      std::istream_iterator< Point > first(ss);
      std::istream_iterator< Point > last;
      temp.insert(temp.end(), first, last);
      if (ss.fail() && !ss.eof())
      {
        is.setstate(std::ios::failbit);
      }
    }
    if (temp.size() != size)
    {
      is.setstate(std::ios::failbit);
    }
    if (is)
    {
      shape.swap(temp);
    }
  }
  return is;
}

std::ostream& lab::operator<<(std::ostream& os, const Shape& shape)
{
  std::ostream::sentry sentry(os);
  if (sentry)
  {
    os << shape.size() << ' ';
    std::copy(shape.cbegin(), shape.cend(), std::ostream_iterator< Point >(os, " "));
  }
  return os;
}
