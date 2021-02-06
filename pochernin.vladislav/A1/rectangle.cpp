#include "rectangle.hpp"

Rectangle::Rectangle(const double width, const double height, const point_t& pos)
{
  figure_.width_ = width;
  figure_.height_ = height;
  figure_.pos_ = pos;
}

Rectangle::~Rectangle()
{}

double Rectangle::getArea() const
{
  return figure_.width_ * figure_.height_;
}

rectangle_t Rectangle::getFrameRect() const
{
  return figure_;
}

void Rectangle::move(const point_t& destination)
{
  figure_.pos_ = destination;
}

void Rectangle::move(const double dx, const double dy)
{
  figure_.pos_.x_ += dx;
  figure_.pos_.y_ += dy;
}
