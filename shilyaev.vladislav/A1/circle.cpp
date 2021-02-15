#include "circle.hpp"
#include <stdexcept>
#include "base-types.hpp"

const double PI = 3.14159265358979323846;

Circle::Circle(double radius, point_t pos):
  radius_(radius),
  pos_(pos)
{
  if (radius_ < 0.0) {
    throw std::invalid_argument("Radius can't be negative");
  }
}

double Circle::getArea() const
{
  return PI * radius_ * radius_;
}

rectangle_t Circle::getFrameRect() const
{
  return rectangle_t{radius_ * 2, radius_ * 2, pos_};
}

void Circle::move(const point_t &pos)
{
  pos_.x = pos.x;
  pos_.y = pos.y;
}

void Circle::move(double dx, double dy)
{
  pos_.x += dx;
  pos_.y += dy;
}
