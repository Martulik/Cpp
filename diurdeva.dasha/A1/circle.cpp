#include "circle.hpp"
#include <cassert>

const double Pi = 3.14;

Circle::Circle(const double rad, const point_t &pos):
  rad_(rad),
  pos_(pos)
{
  assert(rad > 0);
}

double Circle::getArea() const
{
  return rad_ * rad_ * Pi;
}

rectangle_t Circle::getFrameRect() const
{
  return rectangle_t{2 * rad_, 2 * rad_, pos_};
}

void Circle::move(const point_t &newCenter)
{
  pos_ = newCenter;
}

void Circle::move(double dX, double dY)
{
  pos_.x += dX;
  pos_.y += dY;
}
