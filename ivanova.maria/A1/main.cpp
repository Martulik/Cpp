#include <iostream>
#include "shape.hpp"
#include "rectangle.hpp"
#include "circle.hpp"

void Rectangle::print(Shape& shp, std::ostream& out)
{
  out << "Shape:\n" << "::Position: {" << shp.getPos().x << "; " << shp.getPos().y << "}";
  out << "\nSpecific: " << shp.getName();
  out << "\nArea: " << shp.getArea();
}

void testShp(Shape&shp)
{
  shp.move(12, 7);
  std::cout << "new Position: {" << shp.getPos().x << "; " << shp.getPos().y << "}\n";
  shp.move({2, 6});
  std::cout << "new Position: {" << shp.getPos().x << "; " << shp.getPos().y << "}\n";
}
int main() {
  Rectangle *rectangle = new Rectangle(10, 12, {3.0, 18.0});
  Shape *shape0 = rectangle;
  print(rectangle, std::cout);
  testShp(rectangle);
  Circle *circle = new Circle({1, 4}, 12);
  Shape *shape1 = circle;
  print(circle, std::cout);
  testShp(circle);
  delete rectangle;
  delete circle;
  return 0;
}

