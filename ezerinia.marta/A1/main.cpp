#include <iostream>
#include <cassert>
#include "circle.hpp"
#include "rectangle.hpp"

void printFrameRectOfShape(const Shape *shape, std::ostream &out)
{
  assert(shape != nullptr);
  out << "height = " << shape->getFrameRect().height << "  width = "
      << shape->getFrameRect().width;
  out << " center: x = " << shape->getFrameRect().pos.x << ", y = "
      << shape->getFrameRect().pos.y << "\n";
}

void testShape(Shape *shape, std::ostream &out)
{
  assert(shape != nullptr);
  out << "Area = " << shape->getArea() << "\n";
  shape->move({1.1, 2.2});
  printFrameRectOfShape(shape, out);
  shape->move(-1.1, 1.0);
  printFrameRectOfShape(shape, out);
}

int main()
{
  Shape *someShape = new Rectangle(2.0, 4.0, {0.0, 0.0});
  testShape(someShape, std::cout);
  delete someShape;

  someShape = new Circle(111.1, {1.0, -1.0});
  testShape(someShape, std::cout);
  delete someShape;

  return 0;
}
