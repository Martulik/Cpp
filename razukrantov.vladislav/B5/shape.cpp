#include "shape.hpp"

#include <iostream>
#include <algorithm>
#include <iterator>
#include <stdexcept>

#include "functions.hpp"

std::ostream& razukrantov::operator<<(std::ostream& out, const Shape& shape)
{
  out << shape.size() << ' ';
  std::copy(shape.begin(), shape.end(), std::ostream_iterator< Point >(out, " "));
  return out;
}

std::istream& razukrantov::operator>>(std::istream& in, Shape& shape)
{
  if (!in)
  {
    throw(std::invalid_argument("Incorrect reading"));
  }
  size_t count = 0;
  in >> count;
  if (count == 0)
  {
    return in;
  }
  Shape temp;
  temp.reserve(count);
  std::copy_n(std::istream_iterator< Point >(in), count, std::back_inserter(temp));
  std::string str;
  std::getline(in, str);
  if (!in || count != temp.size() || !std::all_of(str.begin(), str.end(), ::isspace))
  {
    throw(std::invalid_argument("Incorrect reading"));
  }
  shape.swap(temp);
  return in;
}

bool razukrantov::isTriangle(const Shape& shape)
{
  return shape.size() == 3;
}

bool razukrantov::isRectangle(const Shape& shape)
{
  return shape.size() == 4;
}

bool razukrantov::isSquare(const Shape& shape)
{
  return isRectangle(shape) && isSidesEqual(shape);
}

bool razukrantov::isPentagon(const Shape& shape)
{
  return shape.size() == 5;
}

bool razukrantov::operator<(const Shape& shape1, const Shape& shape2)
{
  if (shape1.size() < 5 && shape2.size() < 5)
  {
    if (shape1.size() == 4 && shape2.size() == 4)
    {
      return isSquare(shape1) && !isSquare(shape2);
    }
  }
  return shape1.size() < shape2.size();
}
