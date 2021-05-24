#include "vector.hpp"

#include "point.hpp"

namespace lab = savchuk;

lab::Vector::Vector(const Point& start, const Point& finish):
  x_(finish.x - start.x),
  y_(finish.y - start.y)
{
}

lab::Vector& lab::Vector::operator+=(const Vector& other)
{
  x_ += other.x_;
  y_ += other.y_;
  return *this;
}

int lab::operator*(const Vector& lhs, const Vector& rhs)
{
  return lhs.x_ * rhs.x_ + lhs.y_ * rhs.y_;
}

bool lab::operator==(const Vector& lhs, const Vector& rhs)
{
  return lhs.x_ == rhs.x_ && lhs.y_ == rhs.y_;
}

const lab::Vector lab::operator+(const lab::Vector& lhs, const lab::Vector& rhs)
{
  Vector temp = lhs;
  return temp += rhs;
}
