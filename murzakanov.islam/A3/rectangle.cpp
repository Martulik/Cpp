#include "rectangle.hpp"
#include <stdexcept>

murzakanov::Rectangle::Rectangle(const double width, const double height, const murzakanov::point_t& pos):
  width_(width),
  height_(height),
  pos_(pos)
{
  if (width < 0 || height < 0)
  {
    throw std::invalid_argument("Width or height should be more or equal than zero");
  }
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

void murzakanov::Rectangle::scale(const double coef)
{
  if (coef < 0)
  {
    throw std::invalid_argument("Coefficient should be more or equal than zero");
  }
  width_ *= coef;
  height_ *= coef;
}

murzakanov::Rectangle* murzakanov::Rectangle::clone() const
{
  return new Rectangle(*this);
}
