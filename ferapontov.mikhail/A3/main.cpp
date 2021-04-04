#include <iostream>
#include "circle.hpp"
#include "rectangle.hpp"

namespace fer = ferapontov;

void print(std::ostream& out, const fer::Shape& shape)
{
  out << "Name: " << shape.getName() << "\n";
  out << "Coordinate X: " << getX(shape) << "\n";
  out << "Coordinate Y: " << getY(shape) << "\n";
}

void test(fer::Shape* shp, std::ostream& out, const fer::point_t& pos)
{
  print(out, *shp);
  shp->move(pos);
  print(out, *shp);
}

int main()
{
  const fer::point_t point_zero = {0, 0};
  const fer::point_t not_zero = {123, 3};
  fer::Shape* rect = new fer::Rectangle(5, 10, {23, 3});
  fer::Shape* circle = new fer::Circle(3.5, point_zero);
  test(rect, std::cout, point_zero);
  test(circle, std::cout, not_zero);
  delete rect;
  delete circle;
  return 0;
}
