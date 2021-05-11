#include "rectangle.hpp"

#include <cassert>
#include <stdexcept>

namespace lab = shkurov;

lab::Rectangle::Rectangle(const lab::point_t& pos, const double height, const double width):
  center_(pos),
  height_(height),
  width_(width)
{
  if (height_ < 0 || width_ < 0)
  {
    throw std::invalid_argument("Exception: Rectangle has negative side");
  }
}

double lab::Rectangle::getArea() const
{
  return height_ * width_;
}

lab::rectangle_t lab::Rectangle::getFrameRect() const
{
  return {height_, width_, center_};
}

void lab::Rectangle::move(const lab::point_t& newPos)
{
  center_ = newPos;
}

void lab::Rectangle::move(const double moveX, const double moveY)
{
  center_.x += moveX;
  center_.y += moveY;
}

void lab::Rectangle::scaleFigure(const double k)
{
  height_ *= k;
  width_ *= k;
}

const char* lab::Rectangle::getName() const
{
  return "Rectangle";
}
