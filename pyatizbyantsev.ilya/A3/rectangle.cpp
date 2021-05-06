#include "rectangle.hpp"
#include <stdexcept>

pyatizbyantsev::Rectangle::Rectangle(const double valueHeight, const double valueWidth, const point_t& valuePos):
  height_(valueHeight),
  width_(valueWidth),
  pos_(valuePos)
{
  if ((width_ <= 0) || (height_ <= 0))
  {
    throw (std::invalid_argument("Parametrs cannot be negative or equal to zero"));
  }
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

void pyatizbyantsev::Rectangle::doScale(const double scaleCoefficient)
{
  width_ *= scaleCoefficient;
  height_ *= scaleCoefficient;
}

std::string pyatizbyantsev::Rectangle::getName() const
{
  return "Rectangle";
}
