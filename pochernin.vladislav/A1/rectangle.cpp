#include <iostream>
#include <iomanip>

#include "rectangle.hpp"

Rectangle::Rectangle()
{
  figure_.width_ = 0.0;
  figure_.height_ = 0.0;
  figure_.pos_.x_ = 0.0;
  figure_.pos_.y_ = 0.0;
}

Rectangle::Rectangle(const double width, const double height)
{
  figure_.width_ = width;
  figure_.height_ = height;
  figure_.pos_.x_ = 0.0;
  figure_.pos_.y_ = 0.0;
}

Rectangle::Rectangle(const double width, const double height, const point_t& pos)
{
  figure_.width_ = width;
  figure_.height_ = height;
  figure_.pos_ = pos;
}

Rectangle::~Rectangle()
{}

double Rectangle::getArea() const
{
  return figure_.width_ * figure_.height_;
}

rectangle_t Rectangle::getFrameRect() const
{
  return figure_;
}

void Rectangle::move(const point_t& destination)
{
  figure_.pos_ = destination;
}

void Rectangle::move(const double dx, const double dy)
{
  figure_.pos_.x_ += dx;
  figure_.pos_.y_ += dy;
}

void Rectangle::getInfo() const
{
  std::cout << "\n-------------------------------------------\n";
  std::cout << "|" << std::setw(43) << "This is rectangle.|\n";
  std::cout << "|-----------------------------------------|\n";
  std::cout << "|" << "width" << std::setw(15) << "|height"
            << std::setw(10) << "|pos" << std::setw(13) << "|\n";
  std::cout << "|" << figure_.width_ << std::setw(8) << "|" << figure_.height_ << std::setw(11)
            << "|(" << figure_.pos_.x_ << "; " << figure_.pos_.y_ << ")"
            << std::setw(10) << "|\n";
  std::cout << "-------------------------------------------\n";
}
