#include <cassert>
#include "rectangle.hpp"

namespace l = lebedeva;

l::Rectangle::Rectangle(point_t pos, double width, double height):
  pos_(pos),
  width_(width),
  height_(height)
{
  assert((width > 0) && (height > 0));
}

double l::Rectangle::getArea() const
{
  return (height_ * width_);
}

l::rectangle_t l::Rectangle::getFrameRect() const
{
  return { pos_, width_, height_ };
}

std::string l::Rectangle::getName() const
{
  return "Rectangle";
}

void l::Rectangle::move(const point_t& newPos)
{
  pos_ = newPos;
}

void l::Rectangle::move(const double& dx, const double& dy)
{
  pos_.x += dx;
  pos_.y += dy;
}

void l::Rectangle::scale(const double& k)
{
  assert(k > 0);
  width_ *= k;
  height_ *= k;
}
