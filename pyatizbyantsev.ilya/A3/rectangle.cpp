#include "rectangle.hpp"
#include <cassert>

pyatizbyantsev::Rectangle::Rectangle(const double valueHeight, const double valueWidth, const point_t& valuePos):
  height_(valueHeight),
  width_(valueWidth),
  pos_(valuePos)
{
  assert(valueHeight > 0 && valueWidth > 0);
}

double pyatizbyantsev::Rectangle::getArea() const
{
  return width_ * height_;
}

pyatizbyantsev::rectangle_t pyatizbyantsev::Rectangle::getFrameRect() const
{
  return{width_, height_, pos_};
}

void pyatizbyantsev::Rectangle::move(const point_t& newPos)
{
  pos_ = newPos;
}

void pyatizbyantsev::Rectangle::move(const double abscissa, const double ordinate)
{
  pos_.x += abscissa;
  pos_.y += ordinate;
}

void pyatizbyantsev::Rectangle::scale(double scaleCoefficient)
{
  width_ *= scaleCoefficient;
  height_ *= scaleCoefficient;
}
