#include "tools.hpp"

#include <cmath>

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
  return (isRectangle(shape) && getSide(shape[0], shape[1]) == getSide(shape[3], shape[4]));
}

bool lab::isPentagon(const lab::Shape& shape)
{
  return (shape.size() == 5);
}

int lab::getSide(const lab::Point& a, const lab::Point& b)
{
  return (std::pow(a.x - b.x, 2) + std::pow(a.y - b.y, 2));
}

lab::Point lab::getPoint(const lab::Shape& shape)
{
  return shape[0];
}
