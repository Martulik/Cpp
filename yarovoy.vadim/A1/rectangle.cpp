#include "rectangle.hpp"

Rectangle::Rectangle(double width, double height, point_t pos) :
  width_(width),
  height_(height),
  pos_(pos)
{
}

double Rectangle::getArea()const
{
  return (width_ * height_);
}

rectangle_t Rectangle::getFrameRect()const
{
  return { width_, height_, pos_ };
}

void Rectangle::move(const point_t& point)
{
  pos_ = point;
}

void Rectangle::move(const double x, const double y)
{
  pos_.x += + x;
  pos_.y += + y;
}

void Rectangle::print() const
{
  std::cout << "----------------------------------" << std::endl;
  std::cout << "rectangle center - (" << pos_.x << "," << pos_.y << ")" << std::endl;
  std::cout << "rectangle width - " << width_ << std::endl;
  std::cout << "rectangle height - " << height_ << std::endl;
}

