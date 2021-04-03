#include "rectangle.hpp"
#include <stdexcept>

murzakanov::Rectangle::Rectangle(const double width, const double height, const murzakanov::point_t& pos):
  width_(width),
  height_(height),
  pos_(pos)
{
  check(width, "Width should be more or equal than zero");
  check(height, "Height should be more or equal than zero");
}

std::string murzakanov::Rectangle::getName() const
{
  return "Rectangle";
}

double murzakanov::Rectangle::getArea() const
{
  return (width_ * height_);
}

murzakanov::rectangle_t murzakanov::Rectangle::getFrameRect() const
{
  return {width_, height_, pos_};
}

void murzakanov::Rectangle::move(const murzakanov::point_t& point)
{
  pos_ = point;
}

void murzakanov::Rectangle::move(const double dx, const double dy)
{
  pos_.x += dx;
  pos_.y += dy;
}

void murzakanov::Rectangle::doScale(const double coef)
{
  width_ *= coef;
  height_ *= coef;
}

murzakanov::Shape::ShapePtr murzakanov::Rectangle::clone() const
{
  return std::make_shared< murzakanov::Rectangle >(*this);
}
