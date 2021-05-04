#include "rectangle.hpp"

Rectangle::Rectangle(double valueHeight, double valueWidth, point_t valuePos):
  height_(valueHeight),
  width_(valueWidth),
  pos_(valuePos)
  {
  }

double Rectangle::getArea() const
{
  return width_ * height_;
}

rectangle_t Rectangle::getFrameRect() const
{
  return{ width_, height_, pos_ };
}

void Rectangle::move(point_t newPos)
{
  pos_ = newPos;
}

void Rectangle::move(double abscissa, double ordinate)
{
  pos_.x += abscissa;
  pos_.y += ordinate;
}
