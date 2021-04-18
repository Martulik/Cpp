#include "shape.hpp"
#include <stdexcept>
#include <cassert>

double almuhidat::getWidth(const Shape &source)
{
  return source.getFrameRect().width;
}

double almuhidat::getHeight(const Shape &source)
{
  return source.getFrameRect().height;
}

double almuhidat::getX(const Shape &source)
{
  return source.getFrameRect().pos.x;
}

double almuhidat::getY(const Shape &source)
{
  return source.getFrameRect().pos.y;
}

void almuhidat::Shape::scaleNoThrow(double k)
{
  assert(k > 0);
  scaleShape(k);
}

void almuhidat::Shape::scale(double k)
{
  if (k < 0)
  {
    throw std::invalid_argument("Invalid argument");
  }
  scaleShape(k);
}