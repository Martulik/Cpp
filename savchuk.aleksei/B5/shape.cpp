#include "shape.hpp"

#include <iterator>
#include <algorithm>
#include <iostream>
#include <cstddef>
#include <string>

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
  return isRectangle(shape) && (getDistance(shape[0], shape[1]) == getDistance(shape[1], shape[2]));
}

bool lab::isPentagon(const Shape& shape)
{
  return shape.size() == 5;
}
