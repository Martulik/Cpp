#include "rectangle.hpp"

#include <cassert>

namespace lab = savchuk;

lab::Rectangle::Rectangle(const lab::point_t& pos, double width, double height):
  rect_({ pos, width, height })
{
  assert(width > 0 && "The width must be positive");
  assert(height > 0 && "The height must be positive");
}

double lab::Rectangle::getArea() const
{
  return rect_.width * rect_.height;
}

lab::rectangle_t lab::Rectangle::getFrameRect() const
{
  return rect_;
}

void lab::Rectangle::move(const lab::point_t& point)
{
  rect_.pos = point;
}

void lab::Rectangle::move(double dx, double dy)
{
  rect_.pos.x += dx;
  rect_.pos.y += dy;
}

void lab::Rectangle::doScale(double scaleFactor)
{
  rect_.width *= scaleFactor;
  rect_.height *= scaleFactor;
}

std::unique_ptr< lab::Shape > lab::Rectangle::clone() const
{
  return std::unique_ptr< Shape >(new Rectangle(*this));
}
