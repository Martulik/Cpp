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
  Rectangle({x, y}, width, height)
{
}

double borisova::Rectangle::getArea() const
{
  return getWidth() * getHeight();
}

borisova::rectangle_t borisova::Rectangle::getFrameRect() const
{
  return parameters_;
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

std::shared_ptr< borisova::Shape > borisova::Rectangle::clone() const
{
  return std::make_shared< Rectangle >(*this);
}

void borisova::Rectangle::doScale(const double k)
{
  parameters_.width *= k;
  parameters_.height *= k;
}

borisova::Shape* borisova::makeRectangle(const point_t& pos, const double width, const double height)
{
  Shape* temp = new Rectangle(pos, width, height);
  return temp;
}

borisova::Shape* borisova::makeRectangle(const double x, const double y, const double width, const double height)
{
  Shape* temp = new Rectangle(x, y, width, height);
  return temp;
}
