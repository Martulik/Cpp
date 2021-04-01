#include "shape.hpp"
#include <stdexcept>

void murzakanov::Shape::check(double arg, const char* mes)
{
  if (arg < 0)
  {
    throw std::invalid_argument(mes);
  }
}

double murzakanov::Shape::getX() const
{
  return getFrameRect().pos.x;
}

double murzakanov::Shape::getY() const
{
  return getFrameRect().pos.y;
}

double murzakanov::Shape::getWidth() const
{
  return getFrameRect().width;
}

double murzakanov::Shape::getHeight() const
{
  return getFrameRect().height;
}
