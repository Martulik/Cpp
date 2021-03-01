#include <iostream>
#include "shape.hpp"
#include "rectangle.hpp"
#include "circle.hpp"

int main()
{
  void test();
  void print(const Shape & shp, std::ostream & out);
  test();
}

void test()
{
  void print(const Shape & shp, std::ostream & out);
  double x = 0.4;
  double y = 2.56;
  double width = 11.5;
  double height = 0.01;
  double dx = 65.03;
  double dy  =0.99;
  double radius = 43.11;

  point_t point1{x, y};
  point_t point2{dx, dy};

  Shape* rectangle = new Rectangle(point1, width, height);
  print(*rectangle, std::cout);
  rectangle->move(point2);
  std::cout << "Rectangle moved on: " << rectangle->getFrameRect().pos.x << ", " << rectangle->getFrameRect().pos.y << '\n' << '\n';
  delete rectangle;

  Shape* circle = new Circle(x, y, radius);
  print(*circle, std::cout);
  circle->move(dx, dy);
  std::cout << "Circle moved on: " << circle->getFrameRect().pos.x << ", " << circle->getFrameRect().pos.y << '\n';
  delete circle;
}

void print(const Shape& shp, std::ostream& out) {
  out << "Shape:\n" << "::Position: " << shp.getFrameRect().pos.x << ", " << shp.getFrameRect().pos.y;
  out << "\nSpecific: " << shp.getName() << '\n';
}

