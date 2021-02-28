#include <iostream>
#include <cassert>
#include "circle.hpp"
#include "rectangle.hpp"

void getShape(Shape *shape, std::ostream &out)
{
  assert(shape != nullptr);
  out << " center: x = " << shape->getFrameRect().pos.x << ", y = " << shape->getFrameRect().pos.y << std::endl;
  if ((dynamic_cast<const Rectangle *>(shape)) != nullptr) {
    Rectangle *rec = dynamic_cast<Rectangle *>(shape);
    out << ", height = " << rec->getHeight() << ", width = " << rec->getWidth() << std::endl;
  } else if (dynamic_cast<const Circle *>(shape) != nullptr) {
    Circle *cir = dynamic_cast<Circle *>(shape);
    out << ", radius = " << cir->getRadius() << std::endl;
  }
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
  getShape(someShape, std::cout);
  someShape->move(-1.1, 1.0);
  getShape(someShape, std::cout);
  std::cout << "limit rectangle_t for Rectangle ";
  getFrameRectOfShape(someShape, std::cout);
  delete someShape;

  someShape = new Circle(111.1, {1.0, -1.0});
  std::cout << "area of circle = " << someShape->getArea() << std::endl;
  someShape->move({1.1, 2.2});
  getShape(someShape, std::cout);
  someShape->move(-1.1, 1.0);
  getShape(someShape, std::cout);
  std::cout << "limit rectangle_t for Circle ";
  getFrameRectOfShape(someShape, std::cout);
  delete someShape;

  return 0;
}
