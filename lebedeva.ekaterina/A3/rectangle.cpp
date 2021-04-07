#include <stdexcept>
#include "rectangle.hpp"

namespace leb = lebedeva;

leb::Rectangle::Rectangle(point_t pos, double width, double height):
  pos_(pos),
  width_(width),
  height_(height)
{
  if ((width < 0) || (height < 0))
  {
    throw std::invalid_argument("Could not create shape with negative parameters.");
  }
}

double leb::Rectangle::getArea() const
{
  return (height_ * width_);
}

leb::rectangle_t leb::Rectangle::getFrameRect() const
{
  return { pos_, width_, height_ };
}

std::string leb::Rectangle::getName() const
{
  return "Rectangle";
}

std::shared_ptr< leb::Shape > leb::Rectangle::clone() const
{
  return std::make_shared< Rectangle >(*this);
}

void leb::Rectangle::move(const point_t& newPos)
{
  pos_ = newPos;
}

void leb::Rectangle::move(double dx, double dy)
{
  pos_.x += dx;
  pos_.y += dy;
}

void leb::Rectangle::doScale(double k)
{
  width_ *= k;
  height_ *= k;
}
