#include "shape.hpp"
#include <stdexcept>

void ezerinia::Shape::scale(double k)
{
  if (k < 0.0) {
    throw std::invalid_argument("The coefficient of scale must be non-negative");
  }
  doScale(k);
}

double ezerinia::getX(const Shape &src)
{
  return src.getFrameRect().pos.x;
}

double ezerinia::getY(const Shape &src)
{
  return src.getFrameRect().pos.y;
}

double ezerinia::getWidth(const Shape &src)
{
  return src.getFrameRect().width;
}

double ezerinia::getHeight(const Shape &src)
{
  return src.getFrameRect().height;
}
