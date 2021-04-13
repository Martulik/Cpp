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

void shkurov::Rectangle::move(const shkurov::point_t& newPos)
{
  center_ = newPos;
}

void shkurov::Rectangle::move(const double moveX, const double moveY)
{
  center_.x += moveX;
  center_.y += moveY;
}

void shkurov::Rectangle::scaleFigure(const double k)
{
  height_ *= k;
  width_ *= k;
}

const char* shkurov::Rectangle::getName() const
{
  return "Rectangle";
}
