#include "tools.hpp"

#include <cmath>
#include <algorithm>
#include <iostream>
#include <random>
#include <ctime>
#include <cassert>

namespace lab = shkurov;

std::mt19937 rnd(std::time(NULL));

unsigned int lab::countVertices(unsigned int sum, const lab::Shape& cur)
{
  return (sum + cur.size());
}

lab::tupleCount lab::accumFigures(lab::tupleCount& prev, const lab::Shape& cur)
{
  if (isTriangle(cur))
  {
    std::get< 0 >(prev)++;
  }
  if (isSquare(cur))
  {
    std::get< 1 >(prev)++;
  }
  if (isRectangle(cur))
  {
    std::get< 2 >(prev)++;
  }

  return prev;
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

    dist.push_back(getSquaredDistance(shape[0], shape[1]));
    dist.push_back(getSquaredDistance(shape[0], shape[2]));
    dist.push_back(getSquaredDistance(shape[0], shape[3]));

    auto diagIt = std::max_element(dist.begin(), dist.end());
    int diag1 = *diagIt;

    size_t pointIdx = diagIt - dist.begin() + 1;
    int diag2;

    dist.erase(diagIt);

    if (pointIdx == 1)
    {
      diag2 = getSquaredDistance(shape[2], shape[3]);
    }
    else if (pointIdx == 2)
    {
      diag2 = getSquaredDistance(shape[1], shape[3]);
    }
    else if (pointIdx == 3)
    {
      diag2 = getSquaredDistance(shape[1], shape[2]);
    }

    return (dist[0] == dist[1] && diag1 == diag2);
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

lab::Shape lab::rectGen(bool square)
{
  std::uniform_int_distribution< int > coordGen(-10000, 10000);

  Point startPoint{coordGen(rnd), coordGen(rnd)};

  int shiftX = coordGen(rnd);
  int shiftY = coordGen(rnd);

  if (square)
  {
    shiftY = shiftX;
  }

  Point secondPoint{startPoint.x + shiftX, startPoint.y + shiftY};

  return {startPoint, secondPoint, {startPoint.x + shiftX, startPoint.y}, {startPoint.x, startPoint.y + shiftY}};
}

lab::Shape lab::rsGen(unsigned int r, unsigned int s)
{
  assert(r != 0 && s != 0);

  std::uniform_int_distribution< unsigned int > probabilityOfShape(1, r  + s);

  unsigned int number = probabilityOfShape(rnd);

  return rectGen(r < number);
}
