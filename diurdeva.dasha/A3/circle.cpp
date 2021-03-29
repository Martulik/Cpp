#include "circle.hpp"
#include <stdexcept>

const double Pi = 3.14;

diurdeva::Circle::Circle(const double rad, const point_t &pos):
  rad_(rad),
  pos_(pos)
{
  if (rad < 0.0) {
    throw (std::invalid_argument("Negative parametrs. The shape could not be created"));
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

void diurdeva::Circle::move(const double dX, const double dY)
{
  pos_.x += dX;
  pos_.y += dY;
}

std::shared_ptr< diurdeva::Shape > diurdeva::Circle::clone() const
{
  return std::make_shared< Circle >(*this);
}

void diurdeva::Circle::doScale(const double factor)
{
  rad_ *= factor;
}
