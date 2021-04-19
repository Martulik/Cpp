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

double shkurov::getX(const shkurov::Shape& shape)
{
  return shape.getFrameRect().pos.x;
}

double shkurov::getY(const shkurov::Shape& shape)
{
  return shape.getFrameRect().pos.y;
}

double shkurov::getHeight(const shkurov::Shape& shape)
{
  return shape.getFrameRect().height;
}

double shkurov::getWidth(const shkurov::Shape& shape)
{
  return shape.getFrameRect().width;
}
