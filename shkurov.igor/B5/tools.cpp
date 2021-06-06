#include "tools.hpp"

#include <cmath>
#include <algorithm>

namespace lab = shkurov;

unsigned int lab::countVertices(unsigned int sum, const lab::Shape& cur)
{
  return (sum + cur.size());
}

bool lab::isTriangle(const lab::Shape& shape)
{
  return (shape.size() == 3);
}

bool lab::isRectangle(const lab::Shape& shape)
{
  return (shape.size() == 4);
}

bool lab::isSquare(const lab::Shape& shape)
{
  if (isRectangle(shape))
  {
    std::vector< int > dist;

    for (size_t i = 0; i < 4; i++)
    {
      for (size_t j = i + 1; j < 4; j++)
      {
        dist.push_back(getSquaredDistance(shape[i], shape[j]));
      }
    }

    int diag1 = *std::max_element(dist.begin(), dist.end());
    std::remove(dist.begin(), dist.end(), diag1);
    int diag2 = *std::max_element(dist.begin(), std::prev(dist.end()));
    std::remove(dist.begin(), dist.end(), diag2);

    return ((dist[0] == dist[1] && dist[1] == dist[2] && dist[2] == dist[3]) && (dist[4] == dist[5]));
  }

  return false;
}

bool lab::isPentagon(const lab::Shape& shape)
{
  return (shape.size() == 5);
}

int lab::getSquaredDistance(const lab::Point& a, const lab::Point& b)
{
  return (std::pow(a.x - b.x, 2) + std::pow(a.y - b.y, 2));
}

lab::Point lab::getPoint(const lab::Shape& shape)
{
  return shape[0];
}
