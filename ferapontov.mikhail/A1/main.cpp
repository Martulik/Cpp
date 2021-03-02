#include <iostream>
#include "circle.hpp"
#include "rectangle.hpp"

void print(std::ostream& out, const Shape& shape)
{
  out << "Name: " << shape.getName() << "\n";
  out << "Coordinate X: " << shape.getFrameRect().pos.x << "\n";
  out << "Coordinate Y: " << shape.getFrameRect().pos.y << "\n";
}

void test(Shape* shp, std::ostream& out, const point_t& pos)
{
  print(out, *shp);
  shp->move(pos);
  print(out, *shp);
}

int main()
{
  const point_t point_zero = {0, 0};
  const point_t not_zero = {123, 3};
  Shape* rect = new Rectangle(5, 10, {23,3});
  Shape* circle = new Circle(3.5, point_zero);
  test(rect, std::cout, point_zero);
  test(circle, std::cout, not_zero);
  delete rect;
  delete circle;
  return 0;
}
