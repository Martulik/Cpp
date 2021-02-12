#include "rectangle.hpp"
#include <stdexcept>
#include "base-types.hpp"

Rectangle::Rectangle(float width, float height, point_t pos):
  width_(width),
  height_(height),
  pos_(pos)
{
  if (width_ < 0.0 || height_ < 0.0) {
    throw std::invalid_argument("Width and height can't be negative");
  }
}

float Rectangle::getArea() const
{
  return width_ * height_;
}

rectangle_t Rectangle::getFrameRect() const
{
  return rectangle_t{width_, height_, pos_};
}

void Rectangle::move(const point_t &pos)
{
  pos_.x = pos.x;
  pos_.y = pos.y;
}

void Rectangle::move(float dx, float dy)
{
  pos_.x += dx;
  pos_.y += dy;
}
