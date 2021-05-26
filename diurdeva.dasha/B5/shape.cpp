#include "shape.hpp"
#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>

const int TRIANGLE_TOPS = 3;
const int QUADRANGLE_TOPS = 4;
const int PENTAGON_TOPS = 5;

std::istream& diurdeva::operator>>(std::istream& in, Shape& shape)
{
  unsigned int numberOfVertices = 0;
  in >> numberOfVertices;
  if (!in || numberOfVertices < 1) {
    in.setstate(std::ios::failbit);
    return in;
  }
  Shape shapeTemp;
  shapeTemp.reserve(numberOfVertices);
  std::istream_iterator< Point > istream_iter(in);
  std::copy_n(istream_iter, numberOfVertices, std::back_inserter(shapeTemp));
  if ((!in && !in.eof()) || numberOfVertices != shapeTemp.size() || shapeTemp.size() < 3) {
    in.setstate(std::ios_base::failbit);
    return in;
  }
  shape = shapeTemp;
  return in;
}

std::ostream& diurdeva::operator<<(std::ostream& out, const Shape& shape)
{
  out << shape.size() << ' ';
  std::copy(shape.begin(), shape.end(), std::ostream_iterator<Point>(out, " "));
  return out;
}

diurdeva::ShapeType diurdeva::getType(const Shape& shape)
{
  const int size = shape.size();
  switch (size)
  {
  case TRIANGLE_TOPS:
    return TRIANGLE;
  case QUADRANGLE_TOPS:
  {
    std::vector< int > side;
    side.reserve(size);
    std::transform(std::next(shape.begin()), shape.end(), shape.begin(), std::back_inserter(side), squareDistance);
    if (std::count(side.begin(), side.end(), side.front()) == side.size()) {
      return SQUARE;
    } else if ((side[0] == side[2]) && (side[1] == side[3])) {
      return RECTANGLE;
    }
    return DEFAULT;
  }
  case PENTAGON_TOPS:
    return PENTAGON;
  default:
    return DEFAULT;
  }
}

bool diurdeva::isTriangle(const Shape& shape)
{
  return getType(shape) == TRIANGLE;
}

bool diurdeva::isRectangle(const Shape& shape)
{
  return getType(shape) == RECTANGLE;
}

bool diurdeva::isSquare(const Shape& shape)
{
  return getType(shape) == SQUARE;
}

bool diurdeva::isPentagon(const Shape& shape)
{
  return getType(shape) == PENTAGON;
}
