#include "rectangle.hpp"

ivanova::Rectangle::Rectangle(double height, double width, ivanova::point_t pos):
        height_(height),
        width_(width),
        pos_(pos)
{
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

void ivanova::Rectangle::scale(double k)
{
  height_ *= k;
  width_ *= k;
}
