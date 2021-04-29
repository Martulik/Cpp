#include "shape.hpp"
#include <stdexcept>

void borisova::Shape::scale(const double k)
{
  if (k <= 0)
  {
    throw (std::invalid_argument("Negative Coefficient for scale"));
  }
  doScale(k);
}

double borisova::getX(const Shape& obj)
{
  return obj.getFrameRect().pos.x;
}

double borisova::getY(const Shape& obj)
{
  return obj.getFrameRect().pos.y;
}

double borisova::getWidth(const Shape& obj)
{
  return obj.getFrameRect().width;
}

double borisova::getHeight(const Shape& obj)
{
  return obj.getFrameRect().height;
}

double borisova::getLeft(const Shape& obj)
{
  return (getX(obj) - getWidth(obj) / 2);
}

double borisova::getRight(const Shape& obj)
{
  return (getX(obj) + getWidth(obj) / 2);
}

double borisova::getTop(const Shape& obj)
{
  return (getY(obj) + getHeight(obj) / 2);
}

double borisova::getBottom(const Shape& obj)
{
  return (getY(obj) - getHeight(obj) / 2);
}
