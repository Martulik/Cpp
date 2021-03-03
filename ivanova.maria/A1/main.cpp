#include <iostream>
#include "rectangle.hpp"
#include "circle.hpp"

void print(const Shape& shp, std::ostream& out)
{
  out << "Shape:\n" << "::Position: {" << shp.getFrameRect().pos.x << "; " << shp.getFrameRect().pos.y << "}";
  out << "\nSpecific: " << shp.getName();
  out << "\nArea: " << shp.getArea();
}

void testShp(Shape&shp, std::ostream& out)
{
  double x0 = shp.getFrameRect().pos.x;
  double y0 = shp.getFrameRect().pos.y;
  double dx = 12;
  double dy = 7;
  shp.move(dx, dy);
  bool test = ((shp.getFrameRect().pos.x) == x0+dx)&&((shp.getFrameRect().pos.y == y0+dy));
  out << "\nMove passed" << (test? "yes": "no");
  point_t newPos = {2, 6};
  shp.move(newPos);
  test = ((shp.getFrameRect().pos.x == newPos.x)&&(shp.getFrameRect().pos.y == newPos.y));
  out << "\nMove passed" << (test? "yes": "no");
}

int main()
{
  Shape *rectangle = new Rectangle(10, 12, {3.0, 18.0});
  print(*rectangle, std::cout);
  testShp(*rectangle, std::cout);
  Shape *circle = new Circle({1, 4}, 12);
  print(*circle, std::cout);
  testShp(*circle, std::cout);
  delete rectangle;
  delete circle;
  return 0;
}
