#include "rectangle.hpp"
#include <cassert>
#include <stdexcept>

namespace poz = pozdnyakov;

poz::Rectangle::Rectangle(double width, double height, point_t center):
  rec_(rectangle_t{center, width, height})
{
  if (!(width > 0 && height > 0))
  {
    throw std::invalid_argument("Invalid argument");
  }
}
double poz::Rectangle::getArea() const
{
  return rec_.width * rec_.height;
}

poz::rectangle_t pozdnyakov::Rectangle::getFrameRect() const
{
  return rec_;
}

void poz::Rectangle::move(const point_t point)
{
  rec_.pos = point;
}

void poz::Rectangle::move(const double dx, const double dy)
{
  rec_.pos.x += dx;
  rec_.pos.y += dy;
}

void poz::Rectangle::unsafeScale(double coef)
{
  rec_.width *= coef;
  rec_.height *= coef;
}

