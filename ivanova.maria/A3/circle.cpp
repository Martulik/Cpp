#include "circle.hpp"
#include <cassert>

ivanova::Circle::Circle(ivanova::point_t ctr, double rad):
  ctr_(ctr),
  radius_(rad)
{
  assert(rad > 0);
}

double ivanova::Circle::getArea() const
{
  const double PI = 3.14;
  return radius_ * radius_ * PI;
}

ivanova::rectangle_t ivanova::Circle::getFrameRect() const
{
  return ivanova::rectangle_t{2 * radius_, 2 * radius_, ctr_};
}

void ivanova::Circle::move(const ivanova::point_t &newPos)
{
  ctr_ = newPos;
}

void ivanova::Circle::move(double dx, double dy)
{
  ctr_.x += dx;
  ctr_.y += dy;
}

std::string ivanova::Circle::getName() const
{
  return "Circle";
}

void ivanova::Circle::scaleShape(double k)
{
  assert(k > 0);
  radius_ *= k;
}

ivanova::Shape::shared ivanova::Circle::clone() const
{
  return std::make_shared< Circle >(*this);
}
