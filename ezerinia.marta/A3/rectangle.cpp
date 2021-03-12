#include "rectangle.hpp"
#include <cassert>

ezerinia::Rectangle::Rectangle(double width, double height, point_t center):
  width_(width),
  height_(height),
  center_(center)
{
  assert(width > 0 && height > 0);
}

double ezerinia::Rectangle::getArea() const
{
  return height_ * width_;
}

ezerinia::rectangle_t ezerinia::Rectangle::getFrameRect() const
{
  return ezerinia::rectangle_t{width_, height_, center_}; //ezerinia:: нужно ли
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
  assert(k > 0);
  width_ *= k;
  height_ *= k;
}
