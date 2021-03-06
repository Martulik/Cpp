#include "circle.hpp"
#include <cmath>
#include <cassert>

namespace dan = doroshin;

dan::Circle::Circle(point_t pos, double r):
  pos_(pos),
  radius_(r)
{
  assert(radius_ >= 0);
}

double dan::Circle::getArea() const
{
  return M_PI * radius_ * radius_;
}

dan::rectangle_t dan::Circle::getFrameRect() const
{
  return rectangle_t{ 2 * radius_, 2 * radius_, pos_ };
}

void dan::Circle::move_rel(point_t vec)
{
  pos_.x += vec.x;
  pos_.y += vec.y;
}

void dan::Circle::move_abs(point_t point)
{
  pos_ = point;
}

void dan::Circle::scale(double s)
{
  radius_ *= fabs(s);
}

std::unique_ptr<dan::Shape> dan::make_shape(const Circle& c)
{
  Circle* ptr = new Circle(c);
  return std::unique_ptr<Shape>(ptr);
}
