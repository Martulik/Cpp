#include "tools.hpp"
#include <cmath>
#include <limits>
#include <vector>
#include <algorithm>
#include <array>
#include "shape.hpp"

std::array< int, 6 > murzakanov::calculateSides(const murzakanov::Shape& shp)
{
  int ab = getDistanceSquared(shp[0], shp[1]);
  int ac = getDistanceSquared(shp[0], shp[2]);
  int ad = getDistanceSquared(shp[0], shp[3]);
  int bc = getDistanceSquared(shp[1], shp[2]);
  int bd = getDistanceSquared(shp[1], shp[3]);
  int cd = getDistanceSquared(shp[2], shp[3]);
  return std::array< int, 6 >{ ab, ac, ad, bc, bd, cd };
}

int murzakanov::calculateVertices(const std::vector< murzakanov::Shape >& shps)
{
  int vertices = 0;
  for (size_t i = 0; i < shps.size(); i++)
  {
    vertices += shps[i].size();
  }
  return vertices;
}

int murzakanov::getDistanceSquared(const Point& p1, const Point& p2)
{
  int dx = p1.x - p2.x;
  int dy = p1.y - p2.y;
  return dx * dx + dy * dy;
}

void murzakanov::sortShapes(std::vector< murzakanov::Shape >& shps)
{
  std::vector< murzakanov::Shape > temp;
  std::copy_if(shps.begin(), shps.end(), std::back_inserter(temp), murzakanov::isTriangle);
  std::copy_if(shps.begin(), shps.end(), std::back_inserter(temp), murzakanov::isSquare);
  std::copy_if(shps.begin(), shps.end(), std::back_inserter(temp), murzakanov::isRectangle);
  shps.erase(std::remove_if(shps.begin(), shps.end(), isTriangle), shps.end());
  shps.erase(std::remove_if(shps.begin(), shps.end(), isSquare), shps.end());
  shps.erase(std::remove_if(shps.begin(), shps.end(), isRectangle), shps.end());
  std::copy(shps.begin(), shps.end(), std::back_inserter(temp));
  shps = temp;
}
