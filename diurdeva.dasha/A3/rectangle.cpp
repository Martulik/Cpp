#include "rectangle.hpp"
#include <stdexcept>

diurdeva::Rectangle::Rectangle(const double width, const double height, const point_t &pos):
  width_(width),
  height_(height),
  pos_(pos)
{
  if ((width < 0.0) || (height < 0.0)) {
    throw (std::invalid_argument("Negative parametrs"));
  }
}

double diurdeva::Rectangle::getArea() const
{
  return (width_ * height_);
}

diurdeva::rectangle_t diurdeva::Rectangle::getFrameRect() const
{
  return {width_, height_, pos_};
}

void diurdeva::Rectangle::move(const point_t &newCenter)
{
  pos_ = newCenter;
}

void diurdeva::Rectangle::move(double dX, double dY)
{
  pos_.x += dX;
  pos_.y += dY;
}

void diurdeva::Rectangle::scale(const double factor)
{
  if (factor < 0.0) {
    throw (std::invalid_argument("Negative factor"));
  }
  width_ *= factor;
  height_ *= factor;
}
