#include "circle.hpp"
#include <cassert>
#include <stdexcept>

namespace poz = pozdnyakov;

poz::Circle::Circle(double rad, point_t center):
  center_(center),
  rad_(rad)
{
  if (rad <= 0)
  {
    throw std::invalid_argument("Invalid argument");
  }
}

double poz::Circle::getArea() const
{
  const double PI = 3.1415;
  return PI * rad_ * rad_;
}

poz::rectangle_t poz::Circle::getFrameRect() const
{
  return rectangle_t{center_, 2 * rad_, 2 * rad_};
}

void poz::Circle::move(const point_t point)
{
  center_ = point;
}

void poz::Circle::move(const double dx, const double dy)
{
  center_.x += dx;
  center_.y += dy;
}

void poz::Circle::unsafeScale(double coef)
{
  rad_ *= coef;
}
