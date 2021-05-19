#include "shape.hpp"
#include <iostream>
#include <iterator>

namespace lab = borisova;

bool lab::operator<(const Shape& firstShape, const Shape& secondShape)
{
  if ((firstShape.size() == secondShape.size()) && (firstShape.size() == 4))
  {
    return isSquare(firstShape);
  }
  else
  {
    return firstShape.size() < secondShape.size();
  }
}

bool lab::isTriangle(const Shape& shape)
{
  return (shape.size() == 3);
}

bool lab::isSquare(const Shape& shape)
{
  return (isRectangle(shape) &&
    getDistance(shape.at(0), shape.at(1)) == getDistance(shape.at(1), shape.at(2)));
}

bool lab::isRectangle(const Shape& shape)
{
  if (shape.size() == 4)
  {
    if (isPerpendicularity(shape.at(0), shape.at(1), shape.at(2)) &&
      isPerpendicularity(shape.at(1), shape.at(2), shape.at(3)) &&
      isPerpendicularity(shape.at(2), shape.at(3), shape.at(0)))
    {
    return true;
    }
  }
  return false;
}

bool lab::isPentagon(const Shape& shape)
{
  return (shape.size() == 5);
}

std::istream& lab::operator>>(std::istream& in, Shape& shape)
{
  int peaks;
  Point point;
  in >> std::noskipws;
  in >> peaks;
  if (in.fail() || in.eof() || peaks <= 2)
  {
    throw std::invalid_argument("Invalid figure\n");
  }
  for (int i = 0; i < peaks; i++)
  {
    in >> std::skipws;
    in >> point;
    shape.push_back(point);
  }
  if (shape.size() != peaks)
  {
    throw std::invalid_argument("Invalid number of peaks\n");
  }
  return in;
}

std::ostream& lab::operator<<(std::ostream& out, const Shape& shape)
{
  out << shape.size() << " ";
  std::copy(shape.begin(), shape.end(), std::ostream_iterator< Point >(out, " "));
  return out;
}
