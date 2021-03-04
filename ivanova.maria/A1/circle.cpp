#include "circle.hpp"

Circle::Circle(point_t ctr, double rad):
  ctr_(ctr),
  radius_(rad)
{
}

double Circle::getArea() const
{
  const double PI = 3.14;
  return radius_ * radius_ * PI;
}

rectangle_t Circle::getFrameRect() const
{
  return rectangle_t {2 * radius_, 2 * radius_, ctr_};
}

void Circle::move(const point_t &newPos)
{
  ctr_ = newPos;
}

void Circle::move(double dx, double dy)
{
  ctr_.x =+ dx;
  ctr_.y =+ dy;
}
std::string Circle::getName() const
{
  return "Circle";
}
