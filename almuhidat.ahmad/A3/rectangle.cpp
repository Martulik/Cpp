#include "rectangle.hpp"
#include <cassert>

almuhidat::Rectangle::Rectangle(double height, double width, almuhidat::point_t pos):
  height_(height),
  width_(width),
  pos_(pos)
{
  assert(width > 0 && height > 0);
}

double almuhidat::Rectangle::getArea() const
{
  return height_ * width_;
}

almuhidat::rectangle_t almuhidat::Rectangle::getFrameRect() const
{
  return almuhidat::rectangle_t{height_, width_, pos_};
}

void almuhidat::Rectangle::move(const almuhidat::point_t &newPos)
{
  pos_ = newPos;
}

void almuhidat::Rectangle::move(double dx, double dy)
{
  pos_.x += dx;
  pos_.y += dy;
}

std::string almuhidat::Rectangle::getName() const
{
  return "Rectangle";
}

void almuhidat::Rectangle::scaleShape(double k)
{
  assert(k > 0);
  height_ *= k;
  width_ *= k;
}

almuhidat::Shape::shared almuhidat::Rectangle::clone() const
{
  return std::make_shared< Rectangle >(*this);
}