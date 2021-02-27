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

int main()
{
  Shape *someShape = new Rectangle(2.0, 4.0, {0.0, 0.0});
  std::cout << "area of rectangle = " << someShape->getArea() << std::endl;
  getRectangle(dynamic_cast<Rectangle *>(someShape));
  someShape->move({1.1, 2.2});
  getRectangle(dynamic_cast<Rectangle *>(someShape));
  someShape->move(-1.1, 1.0);
  getRectangle(dynamic_cast<Rectangle *>(someShape));
  std::cout << "limit rectangle_t for Rectangle ";
  std::cout << "height = " << someShape->getFrameRect().height << "  width = "
            << someShape->getFrameRect().width;
  std::cout << " center: x = " << someShape->getFrameRect().pos.x << ", y = "
            << someShape->getFrameRect().pos.y;

  std::cout << std::endl;
  delete someShape;

  someShape = new Circle(111.1, {1.0, -1.0});
  std::cout << "area of circle = " << someShape->getArea() << std::endl;
  getCircle(dynamic_cast<Circle *>(someShape));
  someShape->move({1.1, 2.2});
  getCircle(dynamic_cast<Circle *>(someShape));
  someShape->move(-1.1, 1.0);
  getCircle(dynamic_cast<Circle *>(someShape));
  std::cout << "limit rectangle_t for Circle ";
  std::cout << "height = " << someShape->getFrameRect().height << "  width = "
            << someShape->getFrameRect().width;
  std::cout << " center: x = " << someShape->getFrameRect().pos.x << ", y = "
            << someShape->getFrameRect().pos.y;
  std::cout << std::endl;
  delete someShape;

  return 0;
}
