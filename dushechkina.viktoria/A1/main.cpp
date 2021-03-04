#include <iostream>

#include "base-types.hpp"
#include "shape.hpp"
#include "rectangle.hpp"
#include "circle.hpp"
void printInfoFrameRect(const Shape* shape, std::ostream& out)
{
  out << "{" << shape->getFrameRect().pos.x << ", " << shape->getFrameRect().pos.y << "}" << '\n';
}

void printParameters(const Shape* shape, std::ostream& out)
{
  out << "Width of shape: ";
  out << shape->getFrameRect().width << '\n';
  out << "Height of shape: ";
  out << shape->getFrameRect().height << '\n';
}

void testShape(Shape* shape, std::ostream& out)
{
  printParameters(shape, out);
  out << "Position: ";
  printInfoFrameRect(shape, out);
  shape->move(1.28, 2.56);
  out << "Shape has moved by value: ";
  printInfoFrameRect(shape, out);
  point_t p{ 1.6, 10.24 };
  shape->move(p);
  out << "Shape has moved to a point: ";
  printInfoFrameRect(shape, out);
  out << "Shape area: ";
  out << shape->getArea() << '\n';
}

int main()
{
  point_t p = {6.4, 3.2};
  double x = 1.28;
  double y = 20.48;

  std::cout << "CIRCLE\n";
  Shape* rect = new Rectangle(x, y, p);
  testShape(rect, std::cout);

  std::cout << "RECTANGLE\n";
  Shape* circle = new Circle(p, x);
  testShape(circle, std::cout);

  delete rect;
  delete circle;
  return 0;
}
