#include "shape.hpp"

#include <iterator>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <cstddef>
#include <string>

#include "vector.hpp"

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

bool lab::isTriangle(const Shape& shape)
{
  return shape.size() == 3;
}

bool lab::isRectangle(const Shape& shape)
{
  return shape.size() == 4;
}

bool lab::isSquare(const Shape& shape)
{
  if (isRectangle(shape))
  {
    Vector v1 = { shape[0], shape[1] };
    Vector v2 = { shape[0], shape[2] };
    Vector v3 = { shape[0], shape[3] };
    if (v1 + v2 == v3)
    {
      return v1 * v1 == v2 * v2;
    }
    else if (v1 + v3 == v2)
    {
      return v1 * v1 == v3 * v3;
    }
    else if (v2 + v3 == v1)
    {
      return v2 * v2 == v3 * v3;
    }
  }
  return false;
}

bool lab::isPentagon(const Shape& shape)
{
  return shape.size() == 5;
}

bool lab::compare(const Shape& lhs, const Shape& rhs)
{
  if (isRectangle(lhs) && isRectangle(rhs))
  {
    if (isSquare(lhs) && isSquare(rhs))
    {
      return true;
    }
    else if (isSquare(lhs))
    {
      return true;
    }
    else if (isSquare(rhs))
    {
      return false;
    }
  }
  return lhs.size() < rhs.size();
}
