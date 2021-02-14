#include <iostream>
#include <iomanip>

#include "circle.hpp"

const double PI = 3.14159265358979323846;

Circle::Circle(const double radius)
{
  figure_.width = 2.0 * radius;
  figure_.height = 2.0 * radius;
  figure_.pos.x = 0.0;
  figure_.pos.y = 0.0;
}

Circle::Circle(const double radius, const point_t& pos)
{
  figure_.width = 2.0 * radius;
  figure_.height = 2.0 * radius;
  figure_.pos = pos;
}

double Circle::getArea() const
{
  return PI * (figure_.width / 2.0) * (figure_.width / 2.0);
}

rectangle_t Circle::getFrameRect() const
{
  return figure_;
}

void Circle::move(const point_t& destination)
{
  figure_.pos = destination;
}

void Circle::move(const double dx, const double dy)
{
  figure_.pos.x += dx;
  figure_.pos.y += dy;
}

void Circle::getInfo() const
{
  std::cout << "\n-------------------------------------------\n";
  std::cout << "This is circle.\n";
  std::cout << "diameter: " << figure_.width << "\n";
  std::cout << "radius: " << figure_.height / 2.0 << "\n";
  std::cout << "pos: " << "(" << figure_.pos.x << "; " << figure_.pos.y << ")\n";
  std::cout << "-------------------------------------------\n";
}
