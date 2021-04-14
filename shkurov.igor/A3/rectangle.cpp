#include "rectangle.hpp"

#include <cassert>
#include <stdexcept>

namespace ss = shkurov;

ss::Rectangle::Rectangle(const ss::point_t& pos, const double height, const double width):
  center_(pos),
  height_(height),
  width_(width)
{
  if (height_ < 0 || width_ < 0)
  {
    throw std::invalid_argument("Exception: Rectangle has negative side");
  }
}

double ss::Rectangle::getArea() const
{
  return height_ * width_;
}

ss::rectangle_t ss::Rectangle::getFrameRect() const
{
  return {height_, width_, center_};
}

void ss::Rectangle::move(const ss::point_t& newPos)
{
  center_ = newPos;
}

void ss::Rectangle::move(const double moveX, const double moveY)
{
  center_.x += moveX;
  center_.y += moveY;
}

void ss::Rectangle::scaleFigure(const double k)
{
  height_ *= k;
  width_ *= k;
}

const char* ss::Rectangle::getName() const
{
  return "Rectangle";
}
