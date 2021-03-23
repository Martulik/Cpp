#include "rectangle.hpp"
#include <stdexcept>

borisova::Rectangle::Rectangle(const point_t& pos, const double width, const double height):
  parameters_{width, height, pos}
{
  if (!((width > 0) && (height > 0)))
  {
    throw (std::invalid_argument("Negative parameters of rectangle"));
  }
}

borisova::Rectangle::Rectangle(const double x, const double y, const double width, const double height):
  parameters_{ width, height, x, y}
{
  if (!((width > 0) && (height > 0)))
  {
    throw (std::invalid_argument("Negative parameters of rectangle"));
  }
}

double borisova::Rectangle::getArea() const
{
  return parameters_.width * parameters_.height;
}

borisova::rectangle_t borisova::Rectangle::getFrameRect() const
{
  return parameters_;
}

void borisova::Rectangle::scale(const double k)
{
  if (k <= 0)
  {
    throw (std::invalid_argument("Negative Coefficient for scale"));
  }
  parameters_.width *= k;
  parameters_.height *= k;
}

void borisova::Rectangle::move(const double dx, const double dy)
{
  parameters_.pos.x += dx;
  parameters_.pos.y += dy;
}

void borisova::Rectangle::move(const point_t& dpos)
{
  parameters_.pos = dpos;
}

std::string borisova::Rectangle::getName() const
{
  return "Rectangle";
}
