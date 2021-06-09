#include "tools.hpp"

#include <cmath>
#include <algorithm>
#include <iostream>
#include <random>
#include <cassert>
#include <functional>

namespace lab = shkurov;

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
  return (allSidesEqual(shape) && isRectangle(shape));
}

bool lab::isPentagon(const lab::Shape& shape)
{
  return (shape.size() == 5);
}

bool lab::allSidesEqual(const lab::Shape& shape)
{
  std::vector< unsigned int > dist;
  std::transform(std::next(shape.begin()), shape.end(), shape.begin(), std::back_inserter(dist), getSquaredDistance);

  unsigned int lastSide = getSquaredDistance(shape.front(), shape.back());

  using std::placeholders::_1;
  return std::all_of(dist.begin(), dist.end(), std::bind(std::equal_to<>(), _1, lastSide));
}

unsigned int lab::getSquaredDistance(const lab::Point& a, const lab::Point& b)
{
  return (std::pow(a.x - b.x, 2) + std::pow(a.y - b.y, 2));
}

lab::Point lab::getPoint(const lab::Shape& shape)
{
  return shape[0];
}

lab::Shape lab::rectGen(bool square, std::mt19937& rnd)
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

  return {startPoint, {startPoint.x + shiftX, startPoint.y}, secondPoint, {startPoint.x, startPoint.y + shiftY}};
}

lab::Shape lab::rsGen(unsigned int r, unsigned int s, std::mt19937& rnd)
{
  assert(r != 0 && s != 0);

  std::uniform_int_distribution< unsigned int > probabilityOfShape(1, r + s);

  unsigned int number = probabilityOfShape(rnd);

  return rectGen(r < number, rnd);
}
