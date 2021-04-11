#include "rectangle.hpp"
#include <stdexcept>

razukrantov::Rectangle::Rectangle(double width, double height, const point_t &center):
  width_(width),
  height_(height),
  center_(center)
{
  if (width_ < 0.0 || height_ < 0.0)
  {
	throw std::invalid_argument("Width and height cannot be negative");
  }
}

double razukrantov::Rectangle::getArea() const
{
  return (width_ * height_);
}

razukrantov::rectangle_t razukrantov::Rectangle::getFrameRect() const
{
  return rectangle_t{width_, height_, center_};
}

void razukrantov::Rectangle::move(const point_t& center)
{
  center_ = center;
}

void razukrantov::Rectangle::move(const double dx, const double dy)
{
  center_.x += dx;
  center_.y += dy;
}

void razukrantov::Rectangle::scale(const double k)
{
  width_ *= k;
  height_ *= k;
}
