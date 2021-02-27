#include <iostream>
#include <cassert>
#include "circle.hpp"
#include "rectangle.hpp"

void getCircle(const Circle *circle, std::ostream &out)
{
  assert(circle != nullptr);
  out << "radius = " << circle->getRadius() << " center: x= "
            << circle->getCenter().x << ", y= " << circle->getCenter().y << std::endl;
}

void getRectangle(const Rectangle *rectangle, std::ostream &out)
{
  assert(rectangle != nullptr);
  out << "height = " << rectangle->getHeight() << "  width = " << rectangle->getWidth()
            << " center: x= " << rectangle->getCenter().x << ", y= " << rectangle->getCenter().y << std::endl;
}

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
  std::cout << "area of rectangle = " << someShape->getArea() << std::endl;
  someShape->move({1.1, 2.2});
  getRectangle(dynamic_cast<Rectangle *>(someShape), std::cout);
  someShape->move(-1.1, 1.0);
  getRectangle(dynamic_cast<Rectangle *>(someShape), std::cout);
  std::cout << "limit rectangle_t for Rectangle ";
  getFrameRectOfShape(someShape, std::cout);
  delete someShape;

  someShape = new Circle(111.1, {1.0, -1.0});
  std::cout << "area of circle = " << someShape->getArea() << std::endl;
  someShape->move({1.1, 2.2});
  getCircle(dynamic_cast<Circle *>(someShape), std::cout);
  someShape->move(-1.1, 1.0);
  getCircle(dynamic_cast<Circle *>(someShape), std::cout);
  std::cout << "limit rectangle_t for Circle ";
  getFrameRectOfShape(someShape, std::cout);
  delete someShape;

  return 0;
}
