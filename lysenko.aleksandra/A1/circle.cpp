#include "circle.hpp"

#include <cassert>

const double PI = 3.1415926;

Circle::Circle(const point_t &pos, const double radius)
{
  pos_ = pos;
  radius_ = radius;
  assert(radius > 0);
}

double Circle::getArea()
{
  return PI * radius_ * radius_;
}

rectangle_t Circle::getFrameRect()
{
  rectangle_t frame{radius_ * 2.0, radius_ * 2.0, &pos_};
  return frame;
}

void Circle::move(const point_t &newPos)
{
  pos_ = newPos;
}

void Circle::move(const double dx, const double dy)
{
  pos_.x += dx;
  pos_.y += dy;
}
