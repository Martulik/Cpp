#include "rectangle.hpp"
#include "exceptions.hpp"
#include <cassert>

pozdnyakov::Rectangle::Rectangle(double width, double height, point_t center):
  rec_(rectangle_t{center, width,height})
{
  assert(width > 0 && height > 0);
  if (!(width > 0 && height > 0))
  {
    throw ShapeArgException();
  }
}
double pozdnyakov::Rectangle::getArea() const
{
  return rec_.width * rec_.height;
}

pozdnyakov::rectangle_t pozdnyakov::Rectangle::getFrameRect() const
{
  return rec_;
}

void pozdnyakov::Rectangle::move(const point_t point)
{
  rec_.pos = point;
}

void pozdnyakov::Rectangle::move(const double dx, const double dy)
{
  rec_.pos.x += dx;
  rec_.pos.y += dy;
}

void pozdnyakov::Rectangle::scale(double coef)
{
  if (coef <= 0)
  {
    throw ScaleException();
  }
  rec_.width *= coef;
  rec_.height *= coef;
}
