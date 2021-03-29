#include "rectangle.hpp"
#include <cassert>

ivanova::Rectangle::Rectangle(double height, double width, ivanova::point_t pos):
  height_(height),
  width_(width),
  pos_(pos)
{
  assert(width > 0 && height > 0);
}

double ivanova::Rectangle::getArea() const
{
  return height_ * width_;
}

ivanova::rectangle_t ivanova::Rectangle::getFrameRect() const
{
  return ivanova::rectangle_t{height_, width_, pos_};
}

void ivanova::Rectangle::move(const ivanova::point_t &newPos)
{
  pos_ = newPos;
}

void ivanova::Rectangle::move(double dx, double dy)
{
  pos_.x += dx;
  pos_.y += dy;
}

std::string ivanova::Rectangle::getName() const
{
  return "Rectangle";
}

void ivanova::Rectangle::scaleShape(double k)
{
  assert(k > 0);
  height_ *= k;
  width_ *= k;
}

ivanova::Shape::shared ivanova::Rectangle::clone() const
{
  return std::make_shared<Rectangle>(*this);
}
