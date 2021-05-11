#include "rectangle.hpp"
#include <stdexcept>

namespace lab = borisova;

lab::Rectangle::Rectangle(const point_t& pos, const double width, const double height):
  parameters_{width, height, pos}
{
  if (!((width > 0) && (height > 0)))
  {
    throw (std::invalid_argument("Negative parameters of rectangle"));
  }
}

lab::Rectangle::Rectangle(const double x, const double y, const double width, const double height):
  Rectangle({x, y}, width, height)
{
}

double borisova::Rectangle::getArea() const
{
  return getFrameRect().height * getFrameRect().width;
}

lab::rectangle_t borisova::Rectangle::getFrameRect() const
{
  return parameters_;
}

void lab::Rectangle::move(const double dx, const double dy)
{
  parameters_.pos.x += dx;
  parameters_.pos.y += dy;
}

void lab::Rectangle::move(const point_t& dpos)
{
  parameters_.pos = dpos;
}

std::string lab::Rectangle::getName() const
{
  return "Rectangle";
}

std::shared_ptr< lab::Shape > lab::Rectangle::clone() const
{
  return std::make_shared< Rectangle >(*this);
}

void lab::Rectangle::doScale(const double k)
{
  parameters_.width *= k;
  parameters_.height *= k;
}

std::unique_ptr< lab::Shape > lab::makeRectangle(const point_t& pos, const double width, const double height)
{
  return std::make_unique< Rectangle > (pos, width, height);
}

std::unique_ptr< lab::Shape > lab::makeRectangle(const double x, const double y, const double width, const double height)
{
  return std::make_unique< Rectangle >(x, y, width, height);
}
