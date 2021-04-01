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

double borisova::Shape::getX() const
{
  return getFrameRect().pos.x;
}

double borisova::Shape::getY() const
{
  return getFrameRect().pos.y;
}

double borisova::Shape::getWidth() const
{
  return getFrameRect().width;
}

double borisova::Shape::getHeight() const
{
  return getFrameRect().height;
}

double borisova::Shape::getLeft() const
{
  return (getX() - getWidth() / 2);
}

double borisova::Shape::getRight() const
{
  return (getX() + getWidth() / 2);
}

double borisova::Shape::getTop() const
{
  return (getY() + getHeight() / 2);
}

double borisova::Shape::getBottom() const
{
  return (getY() - getHeight() / 2);
}
