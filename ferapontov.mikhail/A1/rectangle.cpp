#include "rectangle.hpp"

Rectangle::Rectangle(const double width, const double height, const point_t pos) :
  proportions_({width, height, pos})
{}

double Rectangle::getArea()
{
  return proportions_.width * proportions_.height;
}

rectangle_t Rectangle::getFrameRate()
{
  return proportions_;
}

void Rectangle::move(const point_t& pos)
{
  proportions_.pos = pos;
}
void Rectangle::move(const double dx, const double dy)
{
  proportions_.pos.x += dx;
  proportions_.pos.y += dy;
}