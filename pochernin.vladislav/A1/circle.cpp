#include <iostream>
#include <iomanip>

#include "circle.hpp"

const double PI = 3.14159265358979323846;

Circle::Circle()
{
  figure_.width_ = 0.0;
  figure_.height_ = 0.0;
  figure_.pos_.x_ = 0.0;
  figure_.pos_.y_ = 0.0;
}

Circle::Circle(const double radius)
{
  figure_.width_ = 2.0 * radius;
  figure_.height_ = 2.0 * radius;
  figure_.pos_.x_ = 0.0;
  figure_.pos_.y_ = 0.0;
}

Circle::Circle(const double radius, const point_t& pos)
{
  figure_.width_ = 2.0 * radius;
  figure_.height_ = 2.0 * radius;
  figure_.pos_ = pos;
}

Circle::~Circle()
{}

double Circle::getArea() const
{
  return PI * (figure_.width_ / 2.0) * (figure_.width_ / 2.0);
}

rectangle_t Circle::getFrameRect() const
{
  return figure_;
}

void Circle::move(const point_t& destination)
{
  figure_.pos_ = destination;
}

void Circle::move(const double dx, const double dy)
{
  figure_.pos_.x_ += dx;
  figure_.pos_.y_ += dy;
}

void Circle::getInfo() const
{
  std::cout << "\n-------------------------------------------\n";
  std::cout << "|" << std::setw(43) << "This is circle.|\n";
  std::cout << "|-----------------------------------------|\n";
  std::cout << "|" << "diameter" << std::setw(12) << "|radius"
            << std::setw(10) << "|pos" << std::setw(13) << "|\n";
  std::cout << "|" << figure_.width_ << std::setw(8) << "|" << figure_.width_ / 2.0
            << std::setw(7) << "|(" << figure_.pos_.x_ << "; " << figure_.pos_.y_ << ")"
            << std::setw(10) << "|\n";
  std::cout << "-------------------------------------------\n";
}
