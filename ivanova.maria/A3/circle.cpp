#include "circle.hpp"

ivanova::Circle::Circle(ivanova::point_t ctr, double rad):
        ctr_(ctr),
        radius_(rad)
{
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

void ivanova::Circle::scale(double k)
{
  radius_ *= k;
}
