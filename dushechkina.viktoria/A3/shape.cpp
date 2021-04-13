#include "shape.hpp"

#include <stdexcept>

void dushechkina::Shape::scale(double ratio)
{
  if (ratio < 0.0)
  {
    throw std::invalid_argument("The scaling factor must be positive");
  }
  doScale(ratio);
}

double dushechkina::getX(const Shape& shape)
{
  return shape.getFrameRect().pos.x;
}

double dushechkina::getY(const Shape& shape)
{
  return shape.getFrameRect().pos.y;
}

double dushechkina::getWidth(const Shape& shape)
{
  return shape.getFrameRect().width;
}

double dushechkina::getHeight(const Shape& shape)
{
  return shape.getFrameRect().height;
}
