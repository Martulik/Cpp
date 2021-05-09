#include "shape-utility.hpp"

#include "rectangle.hpp"
#include "circle.hpp"
#include "composite-shape.hpp"

namespace lab = savchuk;

double lab::getWidth(const lab::Shape& shape)
{
  rectangle_t r = shape.getFrameRect();
  return r.width;
}

double lab::getHeight(const lab::Shape& shape)
{
  rectangle_t r = shape.getFrameRect();
  return r.height;
}

double lab::getPosX(const lab::Shape& shape)
{
  rectangle_t r = shape.getFrameRect();
  return r.pos.x;
}

double lab::getPosY(const lab::Shape& shape)
{
  rectangle_t r = shape.getFrameRect();
  return r.pos.y;
}
