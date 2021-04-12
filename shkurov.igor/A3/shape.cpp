#include "shape.hpp"
#include "stdexcept"

void shkurov::Shape::scale(const double k)
{
  if (k < 0)
  {
    throw std::invalid_argument("Exception: scale coefficient must be positive");
  }
  scaleFigure(k);
}

double shkurov::Shape::getX()
{
  return getFrameRect().pos.x;
}

double shkurov::Shape::getY()
{
  return getFrameRect().pos.y;
}

double shkurov::Shape::getHeight()
{
  return getFrameRect().height;
}

double shkurov::Shape::getWidth()
{
  return getFrameRect().width;
}
