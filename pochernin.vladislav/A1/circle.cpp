# define M_PI           3.14159265358979323846

#include "circle.hpp"
 
double Circle::getArea() const
{
  return M_PI* radius_* radius_;
}

rectangle_t Circle::getFrameRect() const
{
  double diameter = radius_ * 2.0;
  return rectangle_t(diameter, diameter, pos_);
}

void Circle::move(point_t destination)
{
  pos_ = destination;
}

void Circle::move(double dx, double dy)
{
  pos_.x_ += dx;
  pos_.y_ += dy;
}
