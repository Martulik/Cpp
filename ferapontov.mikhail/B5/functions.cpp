#include "functions.hpp"

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
