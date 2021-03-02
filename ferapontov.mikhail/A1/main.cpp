#include <iostream>
#include "circle.hpp"
#include "rectangle.hpp"

void print(std::ostream& out, const Shape& shape)
{
  out << "Name: " << shape.getName() << "\n";
  out << "Coordinate X: " << shape.getFrameRect().pos.x << "\n";
  out << "Coordinate Y: " << shape.getFrameRect().pos.y << "\n";
}

int main()
{
  const point_t point_zero = {0, 0};
  Shape* rect = new Rectangle(5, 10, {0,0});
  print(std::cout, *rect);
  rect->move(2, 3.9);
  std::cout << "Rectangle after move() \n";
  print(std::cout, *rect);
  rect->move(point_zero);
  print(std::cout, *rect);
  Shape* circle = new Circle(3.5, point_zero);
  print(std::cout, *circle);
  std::cout << "Circle after move() \n";
  circle->move(4.9, 8.3);
  print(std::cout, *circle);
  circle->move(point_zero);
  print(std::cout, *circle);
  delete rect;
  delete circle;
  return 0;
}
