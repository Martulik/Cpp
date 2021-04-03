#include "rectangle.hpp"

#include <stdexcept>

dushechkina::Rectangle::Rectangle(const double width, const double height, const point_t& pos):
  unit_{ width, height, pos }
{
  if (width < 0.0)
  {
    throw (std::invalid_argument("Width cannot be negative"));
  }
  if (height < 0.0)
  {
    throw (std::invalid_argument("Height cannot be negative"));
  }
}

double dushechkina::Rectangle::getArea() const
{
  return unit_.width * unit_.height;
}

dushechkina::rectangle_t dushechkina::Rectangle::getFrameRect() const
{
  return rectangle_t{ unit_.width, unit_.height, unit_.pos };
}

void dushechkina::Rectangle::move(const point_t& pos)
{
  unit_.pos = pos;
}

void dushechkina::Rectangle::move(const double dx, const double dy)
{
  unit_.pos.x += dx;
  unit_.pos.y += dy;
}

void dushechkina::Rectangle::doScale(const double ratio)
{
  unit_.height *= ratio;
  unit_.width *= ratio;
}

std::shared_ptr< dushechkina::Shape > dushechkina::Rectangle::clone() const
{
  return std::make_shared < Rectangle > (*this);
}
