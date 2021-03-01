#include <iostream>
#include <cassert>
#include "circle.hpp"
#include "rectangle.hpp"

void getFrameRectOfShape(const Shape *shape, std::ostream &out)
{
  assert(shape != nullptr);
  out << "height = " << shape->getFrameRect().height << "  width = "
      << shape->getFrameRect().width;
  out << " center: x = " << shape->getFrameRect().pos.x << ", y = "
      << shape->getFrameRect().pos.y << std::endl;
}

int main()
{
  Shape *someShape = new Rectangle(2.0, 4.0, {0.0, 0.0});
  std::cout << "Area of rectangle = " << someShape->getArea() << std::endl;
  someShape->move({1.1, 2.2});
  getFrameRectOfShape(someShape, std::cout);
  someShape->move(-1.1, 1.0);
  getFrameRectOfShape(someShape, std::cout);
  delete someShape;

  someShape = new Circle(111.1, {1.0, -1.0});
  std::cout << "Area of circle = " << someShape->getArea() << std::endl;
  someShape->move({1.1, 2.2});
  getFrameRectOfShape(someShape, std::cout);
  someShape->move(-1.1, 1.0);
  getFrameRectOfShape(someShape, std::cout);
  delete someShape;

  return 0;
}
