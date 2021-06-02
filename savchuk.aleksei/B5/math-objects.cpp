#include "math-objects.hpp"

#include "point.hpp"

namespace lab = savchuk;

lab::math::Vector::Vector(const Point& start, const Point& finish):
  x_(finish.x - start.x),
  y_(finish.y - start.y)
{
}

lab::math::Vector& lab::math::Vector::operator+=(const Vector& other)
{
  x_ += other.x_;
  y_ += other.y_;
  return *this;
}

int lab::math::operator*(const Vector& lhs, const Vector& rhs)
{
  return lhs.x_ * rhs.x_ + lhs.y_ * rhs.y_;
}

bool lab::math::operator==(const Vector& lhs, const Vector& rhs)
{
  return lhs.x_ == rhs.x_ && lhs.y_ == rhs.y_;
}

const lab::math::Vector lab::math::operator+(const Vector& lhs, const Vector& rhs)
{
  Vector temp = lhs;
  return temp += rhs;
}
