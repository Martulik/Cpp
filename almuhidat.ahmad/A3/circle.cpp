#include "circle.hpp"
#include <cassert>

almuhidat::Circle::Circle(almuhidat::point_t ctr, double rad):
  ctr_(ctr),
  radius_(rad)
{
  assert(rad > 0);
}

double almuhidat::Circle::getArea() const
{
  const double PI = 3.14;
  return radius_ * radius_ * PI;
}

almuhidat::rectangle_t almuhidat::Circle::getFrameRect() const
{
  return almuhidat::rectangle_t{2 * radius_, 2 * radius_, ctr_};
}

void almuhidat::Circle::move(const almuhidat::point_t &newPos)
{
  ctr_ = newPos;
}

void almuhidat::Circle::move(double dx, double dy)
{
  ctr_.x += dx;
  ctr_.y += dy;
}

std::string almuhidat::Circle::getName() const
{
  return "Circle";
}

void almuhidat::Circle::scaleShape(double k)
{
  assert(k > 0);
  radius_ *= k;
}

almuhidat::Shape::shared almuhidat::Circle::clone() const
{
  return std::make_shared< Circle >(*this);
}