#include "shape.hpp"
#include <stdexcept>

void murzakanov::check(double arg, const char* mes)
{
  if (arg < 0)
  {
    throw std::invalid_argument(mes);
  }
}

double murzakanov::getX(const Shape::ShapePtr& shp)
{
  return shp->getFrameRect().pos.x;
}

double murzakanov::getY(const Shape::ShapePtr& shp)
{
  return shp->getFrameRect().pos.y;
}

double murzakanov::getWidth(const Shape::ShapePtr& shp)
{
  return shp->getFrameRect().width;
}

double murzakanov::getHeight(const Shape::ShapePtr& shp)
{
  return shp->getFrameRect().height;
}

void murzakanov::Shape::scale(double coef)
{
  check(coef, "Coefficient should be more or equal than zero");
  doScale(coef);
}
