#include <iostream>
#include <iomanip>

#include "rectangle.hpp"

Rectangle::Rectangle(const double width, const double height)
{
  figure_.width = width;
  figure_.height = height;
  figure_.pos.x = 0.0;
  figure_.pos.y = 0.0;
}

Rectangle::Rectangle(const double width, const double height, const point_t& pos)
{
  figure_.width = width;
  figure_.height = height;
  figure_.pos = pos;
}

double Rectangle::getArea() const
{
  return figure_.width * figure_.height;
}

rectangle_t Rectangle::getFrameRect() const
{
  return figure_;
}

void Rectangle::move(const point_t& destination)
{
  figure_.pos = destination;
}

void Rectangle::move(const double dx, const double dy)
{
  figure_.pos.x += dx;
  figure_.pos.y += dy;
}

void Rectangle::getInfo() const
{
  std::cout << "\n-------------------------------------------\n";
  std::cout << "|" << std::setw(43) << "This is rectangle.|\n";
  std::cout << "|-----------------------------------------|\n";
  std::cout << "|" << "width" << std::setw(15) << "|height"
            << std::setw(10) << "|pos" << std::setw(13) << "|\n";
  std::cout << "|" << figure_.width << std::setw(8) << "|" << figure_.height << std::setw(11)
            << "|(" << figure_.pos.x << "; " << figure_.pos.y << ")"
            << std::setw(10) << "|\n";
  std::cout << "-------------------------------------------\n";
}
