#include "functions.hpp"
#include <algorithm>

int ferapontov::calculateVector(const Point& first, const Point& second)
{
  int x = second.x - first.x;
  int y = second.y - first.y;
  return (x * x + y * y);
}

ferapontov::Point ferapontov::getVertex(const Shape& shp)
{
  return shp.front();
}

void ferapontov::sortShapes(std::vector< Shape >& shapes)
{
  std::vector< Shape >::iterator it1 = std::partition(shapes.begin(), shapes.end(), isTriangle);
  std::vector< Shape >::iterator it2 = std::partition(it1, shapes.end(), isSquare);
  std::partition(it2, shapes.end(), isRectangle);
}
