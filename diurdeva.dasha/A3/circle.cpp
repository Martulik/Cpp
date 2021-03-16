#include "circle.hpp"
#include <stdexcept>

const double Pi = 3.14;

diurdeva::Circle::Circle(const double rad, const point_t &pos):
  rad_(rad),
  pos_(pos)
{
  if (rad < 0.0) {
    throw (std::invalid_argument("Negative parametrs"));
  }
}

double diurdeva::Circle::getArea() const
{
  return (rad_ * rad_ * Pi);
}

diurdeva::rectangle_t diurdeva::Circle::getFrameRect() const
{
  return rectangle_t{2 * rad_, 2 * rad_, pos_};
}

void diurdeva::Circle::move(const point_t &newCenter)
{
  pos_ = newCenter;
}

void diurdeva::Circle::move(double dX, double dY)
{
  pos_.x += dX;
  pos_.y += dY;
}

void diurdeva::Circle::scale(const double factor)
{
  if (factor < 0.0) {
    throw (std::invalid_argument("Negative factor"));
  }
  rad_ *= factor;
}
