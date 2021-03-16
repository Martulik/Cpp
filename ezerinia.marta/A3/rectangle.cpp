#include "rectangle.hpp"
#include <stdexcept>

ezerinia::Rectangle::Rectangle(double width, double height, point_t center):
  width_(width),
  height_(height),
  center_(center)
{
  if (width_ < 0.0 || height < 0.0)
  {
    throw std::invalid_argument("Width and height must be non-negative");
  }
}

double ezerinia::Rectangle::getArea() const
{
  return height_ * width_;
}

ezerinia::rectangle_t ezerinia::Rectangle::getFrameRect() const
{
  return {width_, height_, center_};
}

void ezerinia::Rectangle::move(const ezerinia::point_t &point)
{
  center_ = point;
}

void ezerinia::Rectangle::move(double dx, double dy)
{
  center_.x += dx;
  center_.y += dy;
}

void ezerinia::Rectangle::scale(double k)
{
  if (k < 0.0)
  {
    throw std::invalid_argument("The coefficient of scale must be non-negative");
  }
  width_ *= k;
  height_ *= k;
}
