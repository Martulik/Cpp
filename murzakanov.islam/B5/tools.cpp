#include "tools.hpp"
#include <cmath>
#include <limits>
#include <vector>
#include <algorithm>
#include "shape.hpp"

bool murzakanov::checkIsRectangle(const Shape& shp)
{
  if (shp.size() != 4)
  {
    return false;
  }
  std::vector< int > sides = calculateSides(shp);
  std::sort(sides.begin(), sides.end());
  if (sides[0] == sides[1] && sides[2] == sides[3] && sides[4] == sides[5] && sides[2] != sides[4])
  {
    return true;
  }
  return false;
}

bool murzakanov::checkIsSquare(const Shape& shp)
{
  if (shp.size() != 4)
  {
    return false;
  }
  std::vector< int > sides = calculateSides(shp);
  std::sort(sides.begin(), sides.end());
  if (sides[0] == sides[1] && sides[2] == sides[3] && sides[4] == sides[5] && sides[2] == sides[4])
  {
    return true;
  }
  return false;
}

std::vector< int > murzakanov::calculateSides(const murzakanov::Shape& shp)
{
  int ab = getDistanceSquared(shp[0], shp[1]);
  int ac = getDistanceSquared(shp[0], shp[2]);
  int ad = getDistanceSquared(shp[0], shp[3]);
  int bc = getDistanceSquared(shp[1], shp[2]);
  int bd = getDistanceSquared(shp[1], shp[3]);
  int cd = getDistanceSquared(shp[2], shp[3]);
  return std::vector< int >{ ab, ac, ad, bc, bd, cd };
}

int murzakanov::calculateVertices(const std::vector< murzakanov::Shape >& shp)
{
  int vertices = 0;
  for (size_t i = 0; i < shp.size(); i++)
  {
    vertices += shp[i].size();
  }
  return vertices;
}

int murzakanov::getDistanceSquared(const Point& p1, const Point& p2)
{
  int dx = p1.x - p2.x;
  int dy = p1.y - p2.y;
  return dx*dx + dy*dy;
}
