#include "rectangle.hpp"

#include <cassert>
#include <stdexcept>

shkurov::Rectangle::Rectangle(const shkurov::point_t& pos, const double height, const double width):
  center_(pos),
  height_(height),
  width_(width)
{
  if (height_ < 0 || width_ < 0)
  {
    throw std::invalid_argument("Exception: Rectangle has negative side");
  }
}

double shkurov::Rectangle::getArea() const
{
  return height_ * width_;
}

shkurov::rectangle_t shkurov::Rectangle::getFrameRect() const
{
  return {height_, width_, center_};
}

void shkurov::Rectangle::move(const shkurov::point_t& new_pos)
{
  center_ = new_pos;
}

void shkurov::Rectangle::move(const double move_x, const double move_y)
{
  center_.x += move_x;
  center_.y += move_y;
}

void shkurov::Rectangle::scale(const double k)
{
  if (k < 0)
  {
    throw std::invalid_argument("Exception: Scale coefficient is negative");
  }

  height_ *= k;
  width_ *= k;
}

const char* shkurov::Rectangle::getName() const
{
  return "Rectangle";
}
