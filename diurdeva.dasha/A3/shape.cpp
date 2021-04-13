#include "shape.hpp"
#include <stdexcept>

void diurdeva::Shape::scale(const double k)
{
  if (k < 0.0) {
    throw std::invalid_argument("The coefficient must be non-negative");
  }
  doScale(k);
}

double diurdeva::getX(const diurdeva::Shape& shape)
{
  return shape.getFrameRect().pos.x;
}

double diurdeva::getY(const diurdeva::Shape& shape)
{
  return shape.getFrameRect().pos.y;
}

double diurdeva::getHeight(const diurdeva::Shape& shape)
{
  return shape.getFrameRect().height;
}

double diurdeva::getWidth(const diurdeva::Shape& shape)
{
  return shape.getFrameRect().width;
}
