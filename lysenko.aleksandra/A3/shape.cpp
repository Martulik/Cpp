#include "shape.hpp"
#include <stdexcept>

namespace curr = lysenko;

void curr::Shape::scale(double k)
{
  if (k < 0)
  {
    throw std::invalid_argument("Negative scale for figure is illegal");
  }
  doScale(k);
}

double lysenko::getX(Shape::ShapePtr src)
{
  return src->getFrameRect().pos.x;
}

double lysenko::getY(Shape::ShapePtr src)
{
  return src->getFrameRect().pos.y;
}

double lysenko::getWidth(Shape::ShapePtr src)
{
  return src->getFrameRect().width;
}

double lysenko::getHeight(Shape::ShapePtr src)
{
  return src->getFrameRect().height;
}