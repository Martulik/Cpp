#include "rectangle.hpp"

#include <stdexcept>
#include <string>

namespace curr = lysenko;

curr::Rectangle::Rectangle(double width, double height, point_t& pos):
  width_(width),
  heigh_(height),
  pos_(pos)
{
  if ((height < 0.0) && (width < 0.0))
  {
    throw std::invalid_argument("Height and width of rectangle must be positive");
  }
}

double curr::Rectangle::getArea() const
{
  return (width_ * heigh_);
}

curr::rectangle_t curr::Rectangle::getFrameRect() const
{
  return {width_, heigh_, pos_};
}

void curr::Rectangle::move(const point_t& newPos)
{
  pos_ = newPos;
}

void curr::Rectangle::move(double dx, double dy)
{
  pos_.x += dx;
  pos_.y += dy;
}

std::string curr::Rectangle::getName() const
{
  return "Rectangle";
}

void curr::Rectangle::doScale(double k)
{
  width_ *= k;
  heigh_ *= k;
}

