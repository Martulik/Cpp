#include <iostream>
#include "shape.hpp"
#include "rectangle.hpp"
#include "circle.hpp"

void testAll();
void test(Shape& obj, point_t& dpos, std::ostream& out);
void print(const Shape& obj, std::ostream& out);
void printPos(const Shape& obj, std::ostream& out);
void moving(const Shape& obj, std::ostream& out);

int main()
{
  testAll();
}

void testAll()
{
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
  print(obj, out);
  obj.move(dpos);
  moving(obj, out);
  obj.move(dpos.x, dpos.y);
  moving(obj, out);
}

void print(const Shape& obj, std::ostream& out)
{
  out << "\nShape:\n" << "::Position: ";
  printPos(obj, out);
  out << "\nSpecific: " << obj.getName() << '\n';
}

void printPos(const Shape& obj, std::ostream& out)
{
  out << obj.getFrameRect().pos.x << ", " << obj.getFrameRect().pos.y << '\n';
}

void moving(const Shape& obj, std::ostream& out)
{
  out << "Figure moved on: ";
  printPos(obj, out);
}
