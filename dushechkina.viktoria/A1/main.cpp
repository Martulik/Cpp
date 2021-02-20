#include <iostream>

#include "base-types.hpp"
#include "shape.hpp"
#include "rectangle.hpp"
#include "circle.hpp"
int main()
{
  double x = 1.28;
  double y = 2.56;
  double r = 10.24;
  point_t p1{x, y};
  Shape* circle = new Circle(p1, r);
  std::cout << "CIRCLE" << std::endl
  << "Area of a circle: " << circle->getArea() << std::endl
  << "Frame rect of a circle: " << "{" << circle->getFrameRect().pos.x << ", "
  << circle->getFrameRect().pos.y << "}" << std::endl;
  x = 4;
  y = -1.6;
  point_t p2{x, y};
  circle->move(p2);
  std::cout << "Circle has moved to a point: " << "{" << circle->getFrameRect().pos.x << ", "
  << circle->getFrameRect().pos.y << "}" << std::endl;
  circle->move(x,y);
  std::cout << "Circle has moved by value: " << "{" << circle->getFrameRect().pos.x << ", "
  << circle->getFrameRect().pos.y << "}" << std::endl << std::endl;

  x = 6.4;
  y = 3.2;
  double height = 10.24;
  double width = 20.48;
  point_t p3{x, y};
  Shape* rec = new Rectangle(width, height, p3);
  std::cout << "RECTANGLE" << std::endl
  << "Area of a rectangle: " << rec->getArea() << std::endl
  << "Frame rect of a rectangle: " << "{" << rec->getFrameRect().pos.x << ", "
  << rec->getFrameRect().pos.y << "}" << std::endl;
  x = 1.6;
  y = -1.28;
  point_t p4{x, y};
  rec->move(p4);
  std::cout << "Rectangle has moved to a point: " << "{" << rec->getFrameRect().pos.x << ", "
  << rec->getFrameRect().pos.y << "}" << std::endl;
  rec->move(x, y);
  std::cout << "Rectangle has moved by value: " << "{" << rec->getFrameRect().pos.x << ", "
  << rec->getFrameRect().pos.y << "}" << std::endl;

  delete circle;
  delete rec;
  return 0;
}

