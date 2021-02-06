#include "circle.hpp"

const double PI = 3.14159265358979323846;

Circle::Circle(const double radius, const point_t& pos)
{
  figure_.width_ = 2.0 * radius;
  figure_.height_ = 2.0 * radius;
  figure_.pos_ = pos;
}

Circle::~Circle()
{}

double Circle::getArea() const
{
  return PI * (figure_.width_ / 2.0) * (figure_.width_ / 2.0);
}

rectangle_t Circle::getFrameRect() const
{
  return figure_;
}

void Circle::move(const point_t& destination)
{
  figure_.pos_ = destination;
}

void Circle::move(const double dx, const double dy)
{
  figure_.pos_.x_ += dx;
  figure_.pos_.y_ += dy;
}
