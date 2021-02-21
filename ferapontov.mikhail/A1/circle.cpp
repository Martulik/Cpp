#include "circle.hpp"

Circle::Circle(const double radius, const point_t pos):
  radius_(radius),
  pos_(pos)
{}

double Circle::getArea()
{
  return PI * radius_ * radius_;
}

rectangle_t Circle::getFrameRate()
{
  return {2*radius_, 2*radius_, pos_};
}

void Circle::move(const point_t& pos)
{
  pos_ = pos;
}

void Circle::move(const double dx, const double dy)
{
  pos_.x += dx;
  pos_.y += dy;
}
