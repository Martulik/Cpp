#include <iostream>

#include "shape.hpp"
#include "rectangle.hpp"
#include "circle.hpp"

int main()
{
  double x = 5.25;
  double y = 5.25;
  point_t point{x, y};

  double width = 6.66;
  double height = 7.77;
  Rectangle r = Rectangle(width, height, point);
  Shape* rectangle = &r;

  std::cout << "Rectangle:\n";
  std::cout << "Width is: " << rectangle->getFrameRect().width << std::endl;
  std::cout << "Height is: " << rectangle->getFrameRect().height << std::endl;
  std::cout << "Area is: " << rectangle->getArea() << std::endl;
  std::cout << "Position is: " << rectangle->getFrameRect().pos.x << ", " << rectangle->getFrameRect().pos.y << std::endl;

  x = 3.33;
  y = 3.33;
  rectangle->move(x, y);

  std::cout << "Rectangle moved in: " << rectangle->getFrameRect().pos.x << ", " << rectangle->getFrameRect().pos.y << std::endl << std::endl;

  x = 5.25;
  y = 5.25;

  double radius = 7.77;
  Shape* circle = new Circle(radius, {x, y});

  std::cout << "Circle:\n";
  std::cout << "Radius is: " << circle->getFrameRect().width/2 << std::endl;
  std::cout << "Area is: " << circle->getArea() << std::endl;
  std::cout << "Position is: " << circle->getFrameRect().pos.x << ", " << circle->getFrameRect().pos.y << std::endl;

  x = 7.77;
  y = 7.77;
  point_t point2{x, y};
  circle->move(point2);

  std::cout << "Circle moved in: " << circle->getFrameRect().pos.x << ", " << circle->getFrameRect().pos.y << std::endl;

  delete circle;
}
