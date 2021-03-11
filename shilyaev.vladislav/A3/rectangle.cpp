#include "rectangle.hpp"
#include <stdexcept>

shilyaev::Rectangle::Rectangle(double width, double height, const point_t &pos):
  width_(width),
  height_(height),
  pos_(pos)
{
  if (width_ < 0.0 || height_ < 0.0) {
    throw std::invalid_argument("Width and height can't be negative");
  }
}

double shilyaev::Rectangle::getArea() const
{
  return width_ * height_;
}

shilyaev::rectangle_t shilyaev::Rectangle::getFrameRect() const
{
  return rectangle_t{width_, height_, pos_};
}

shilyaev::Rectangle *shilyaev::Rectangle::clone() const
{
  return new Rectangle(*this);
}

void shilyaev::Rectangle::move(const point_t &pos)
{
  pos_ = pos;
}

void shilyaev::Rectangle::move(double dx, double dy)
{
  pos_.x += dx;
  pos_.y += dy;
}

void shilyaev::Rectangle::scale(double factor)
{
  if (factor < 0.0) {
    throw std::invalid_argument("Scale factor can't be negative");
  }
  width_ *= factor;
  height_ *= factor;
}
