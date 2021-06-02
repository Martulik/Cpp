#include "shape.hpp"

#include <iterator>
#include <algorithm>
#include <iostream>
#include <cstddef>
#include <string>

#include "math-objects.hpp"

namespace lab = savchuk;

std::istream& lab::operator>>(std::istream& is, Shape& shape)
{
  std::istream::sentry sentry(is);
  if (sentry)
  {
    size_t size;
    is >> size;
    if (!is || is.get() != ' ')
    {
      is.setstate(std::ios::failbit);
    }
    Shape temp;
    std::copy_n(std::istream_iterator< Point >(is), size, std::back_inserter(temp));
    if ((is.fail() && is.eof()) && !temp.empty())
    {
      is.clear();
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
    math::Vector v1 = { shape[0], shape[1] };
    math::Vector v2 = { shape[0], shape[2] };
    math::Vector v3 = { shape[0], shape[3] };
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
