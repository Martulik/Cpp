#include "functions.hpp"

#include <algorithm>
#include <iterator>
#include <functional>

bool razukrantov::isSidesEqual(const Shape& shape)
{
  int side = getDistanceSquared(shape.front(), shape.back());
  std::vector< int > sides;
  sides.reserve(shape.size());
  std::transform(shape.begin() + 1, shape.end(), shape.begin(), std::back_inserter(sides), getDistanceSquared);
  return std::all_of(sides.begin(), sides.end(), std::bind(std::equal_to<>(), std::placeholders::_1, side));
}

int razukrantov::getDistanceSquared(const Point& point1, const Point& point2)
{
  const int dx = point1.x - point2.x;
  const int dy = point1.y - point2.y;
  return dx * dx + dy * dy;
}

unsigned int razukrantov::sumVertices(unsigned int sum, const Shape& shape)
{
  return sum + shape.size();
}

razukrantov::Point razukrantov::getFrontPoint(const Shape& shape)
{
  return shape.front();
}

void razukrantov::shapesPartition(std::vector< razukrantov::Shape >& shapes)
{
  auto bound = std::partition(shapes.begin(), shapes.end(), razukrantov::isTriangle);
  bound = std::partition(bound, shapes.end(), razukrantov::isSquare);
  std::partition(bound, shapes.end(), razukrantov::isRectangle);
}
