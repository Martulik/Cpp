#include "rectangle.hpp"
#include <iostream>

Rectangle::Rectangle():
  width_(0),
  height_(0),
  center_(0.0, 0.0)
{
}

Rectangle::Rectangle(double width, double height, point_t center):
  width_(width),
  height_(height),
  center_(center)
{
    if ((width <= 0) || (height <= 0))
    {
        throw ("the width and height must be greater than 0");
    }
}

void Rectangle::showShape()
{
    std::cout << "height = " << height_ << ", width_ = " << width_;
    std::cout << ", center: x = " << center_.x_t << ", y = " << center_.y_t << std::endl;
}

double Rectangle::getArea()
{
    return (height_ * width_);
}

rectangle_t Rectangle::getFrameRect()
{
    return (rectangle_t(width_, height_, center_));
}

void Rectangle::move(const point_t &point)
{
    center_ = point;
}

void Rectangle::move(double x, double y)
{
    center_.x_t += x;
    center_.y_t += y;
}

Rectangle::~Rectangle()
{
}