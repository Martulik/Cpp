#include "rectangle.hpp"

Rectangle::Rectangle(double width, double height, point_t pos):
  width_(width),
  height_(height),
  pos_(pos)
{
}

Rectangle::Rectangle(const Rectangle& other):
  width_(other.width_),
  height_(other.height_),
  pos_(other.pos_)
{
}

Rectangle& Rectangle::operator=(const Rectangle& other)
{
  if (this == &other)
  {
    return *this;
  }
  this->height_ = other.height_;
  this->width_ = other.width_;
  this->pos_ = other.pos_;
  return *this;
}

Rectangle::Rectangle(Rectangle&& other) noexcept
{
  this->height_ = other.height_;
  this->width_ = other.width_;
  this->pos_ = other.pos_;
  other.height_ = 0;
  other.width_ = 0;
  other.pos_ = { 0, 0 };
}
Rectangle& Rectangle::operator=(Rectangle&& other) noexcept
{
  if (&other == this)
  {
    return *this;
  }
  this->height_ = other.height_;
  this->width_ = other.width_;
  this->pos_ = other.pos_;
  other.height_ = 0;
  other.width_ = 0;
  other.pos_ = { 0, 0 };
  return *this;
}

double Rectangle::getArea()const
{
  return (width_ * height_);
}

rectangle_t Rectangle::getFrameRect()const
{
  return { width_, height_, pos_ };
}

void Rectangle::move(const point_t& point)
{
  pos_ = point;
}

void Rectangle::move(const double dx, const double dy)
{
  pos_.x = pos_.x + dx;
  pos_.y = pos_.y + dy;
}

void Rectangle::print() const {
  std::cout << "Rectangle's width is " << width_ << std::endl;
  std::cout << "Rectangle's height is " << height_ << std::endl;
  std::cout << "Rectangle's center is (" << pos_.x << ", " << pos_.y << ")" << std::endl;
}
