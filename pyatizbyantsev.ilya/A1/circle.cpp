#include "circle.hpp"
#include <iostream>
#define PI 3.141592653589793

double Circle::getArea()const
{
  return PI * radius_ * radius_;
}

rectangle_t Circle::getFrameRect()const
{
  return{radius_ * 2, radius_ * 2, pos_};
}

void Circle::move(point_t newPos)
{
  pos_ = newPos;
}

void Circle::move(double abscissa, double ordinate)
{
  pos_.x += abscissa;
  pos_.y += ordinate;
}
