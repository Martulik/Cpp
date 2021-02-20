#include "circle.hpp"
#include <cassert>

const double Pi = 3.14;

Circle::Circle(double rad, point_t &pos):
        rad_(rad),
        pos_(pos)
{
  assert(radius > 0);
}

double Circle::getArea() const
{
  return (rad_ * rad_ * Pi);
}

rectangle_t Circle::getFrameRect() const
{
  return rectangle_t{2 * rad_, 2 * rad_, pos_};
}

void Circle::move(const point_t &newCenter)
{
  pos_ = newCenter;
}

void Circle::move(double axisX, double axisY)
{
  pos_.x += axisX;
  pos_.y += axisY;
}
