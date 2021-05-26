#include "tools.hpp"

#include <algorithm>
#include <iterator>
#include <iostream>
#include <cctype>
#include <functional>

#include "point.hpp"
#include "shape.hpp"

bool murzakanov::checkIsSidesEqual(const murzakanov::Shape& shp)
{
  int last = getDistanceSquared(shp[0], shp[3]);
  std::vector< int > sides;
  sides.reserve(shp.size());
  std::transform(shp.begin() + 1, shp.end(), shp.begin(), std::back_inserter(sides), getDistanceSquared);
  return std::all_of(sides.begin(), sides.end(), std::bind(std::equal_to<>(), std::placeholders::_1, last));
}

int murzakanov::calculateVertices(int vertices, const murzakanov::Shape& shp)
{
  return vertices + shp.size();
}

murzakanov::Point murzakanov::returnFrontPnt(const murzakanov::Shape& shp)
{
  return shp.front();
}

int murzakanov::getDistanceSquared(const Point& p1, const Point& p2)
{
  int dx = p1.x - p2.x;
  int dy = p1.y - p2.y;
  return dx * dx + dy * dy;
}
