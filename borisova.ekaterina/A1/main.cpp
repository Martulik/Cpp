#include <iostream>
#include "shape.hpp"
#include "rectangle.hpp"
#include "circle.hpp"

int main()
{
  void testAll();
  void test(Shape & obj, point_t & dpos, std::ostream & out);
  testAll();
}

void testAll()
{
  void print(const Shape & shp, std::ostream & out);
  void test(Shape & obj, point_t & dpos, std::ostream & out);
  double x = 0.4;
  double y = 2.56;
  double width = 11.5;
  double height = 0.01;
  double dx = 65.03;
  double dy = 0.99;
  double radius = 43.11;

  point_t point1{x, y};
  point_t point2{dx, dy};

  Shape* rectangle = new Rectangle(point1, width, height);
  test(*rectangle, point2, std::cout);
  delete rectangle;

  Shape* circle = new Circle(dx, dy, radius);
  test(*circle, point1, std::cout);
  delete circle;
}

void test(Shape& obj, point_t& dpos, std::ostream& out)
{
  out << "Shape:\n" << "::Position: ";
  out << obj.getFrameRect().pos.x << ", " << obj.getFrameRect().pos.y;
  out << "\nSpecific: " << obj.getName() << '\n';
  obj.move(dpos);
  out << "Figure moved on: ";
  out << obj.getFrameRect().pos.x << ", " << obj.getFrameRect().pos.y << '\n';
  obj.move(dpos.x, dpos.y);
  out << "Figure moved on: ";
  out << obj.getFrameRect().pos.x << ", " << obj.getFrameRect().pos.y << '\n' << '\n';
}
