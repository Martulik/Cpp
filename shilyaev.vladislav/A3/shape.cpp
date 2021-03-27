#include "shape.hpp"
#include <stdexcept>

void shilyaev::Shape::scale(double factor)
{
  if (factor < 0.0) {
    throw std::invalid_argument("Scale factor can't be negative");
  }
  scaleInternal(factor);
}

double shilyaev::getX(const Shape &shape)
{
  return shape.getFrameRect().pos.x;
}

double shilyaev::getY(const Shape &shape)
{
  return shape.getFrameRect().pos.y;
}

double shilyaev::getWidth(const Shape &shape)
{
  return shape.getFrameRect().width;
}

double shilyaev::getHeight(const Shape &shape)
{
  return shape.getFrameRect().height;
}
