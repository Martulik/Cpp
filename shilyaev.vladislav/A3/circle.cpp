#include "circle.hpp"
#include <stdexcept>

const double PI = 3.14159265358979323846;

shilyaev::Circle::Circle(double radius, const point_t &pos):
  radius_(radius),
  pos_(pos)
{
  if (radius < 0.0) {
    throw std::invalid_argument("Radius can't be negative");
  }
}

double shilyaev::Circle::getArea() const
{
  return PI * radius_ * radius_;
}

shilyaev::rectangle_t shilyaev::Circle::getFrameRect() const
{
  return rectangle_t{radius_ * 2, radius_ * 2, pos_};
}

std::unique_ptr< shilyaev::Shape > shilyaev::Circle::clone() const
{
  return std::make_unique< shilyaev::Circle >(*this);
}

void shilyaev::Circle::move(const point_t &pos)
{
  pos_ = pos;
}

void shilyaev::Circle::move(double dx, double dy)
{
  pos_.x += dx;
  pos_.y += dy;
}

void shilyaev::Circle::scaleInternal(double factor)
{
  radius_ *= factor;
}
