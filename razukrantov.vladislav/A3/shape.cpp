#include "shape.hpp"
#include <stdexcept>

void razukrantov::Shape::scale(double k)
{
  if (k < 0)
  {
    throw std::invalid_argument("The coefficient cannot be nehative");
  }
  doScale(k);
}

double::razukrantov::getX(const Shape& shape)
{
  return shape.getFrameRect().pos.x;
}

double::razukrantov::getY(const Shape& shape)
{
  return shape.getFrameRect().pos.y;
}

double::razukrantov::getWidth(const Shape& shape)
{
  return shape.getFrameRect().width;
}

double::razukrantov::getHeight(const Shape& shape)
{
  return shape.getFrameRect().height;
}
