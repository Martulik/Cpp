#include "shape.hpp"
#include <cassert>

double ivanova::getWidth(const Shape &source)
{
  return source.getFrameRect().width;
}
double ivanova::getHeight(const Shape &source)
{
  return source.getFrameRect().height;
}
double ivanova::getX(const Shape &source)
{
  return source.getFrameRect().pos.x;
}
double ivanova::getY(const Shape &source)
{
  return source.getFrameRect().pos.y;
}

void ivanova::Shape::scale(double k)
{
  assert(k>0.0);
  scaleShape(k);
}
