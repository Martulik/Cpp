#include <cassert>
#include "rectangle.hpp"

namespace leb = lebedeva;

leb::Rectangle::Rectangle(point_t pos, double width, double height):
  pos_(pos),
  width_(width),
  height_(height)
{
  assert((width > 0) && (height > 0));
}

double leb::Rectangle::getArea() const
{
  return (height_ * width_);
}

leb::rectangle_t leb::Rectangle::getFrameRect() const
{
  return { pos_, width_, height_ };
}

std::string leb::Rectangle::getName() const
{
  return "Rectangle";
}

void leb::Rectangle::move(const point_t& newPos)
{
  pos_ = newPos;
}

void leb::Rectangle::move(double dx, double dy)
{
  pos_.x += dx;
  pos_.y += dy;
}

void leb::Rectangle::scale(double k)
{
  assert(k > 0);
  width_ *= k;
  height_ *= k;
}
