#include <iostream>
#include "shape.hpp"
#include "rectangle.hpp"
#include "circle.hpp"

int main()
{
  void testRectangle();
  void testCircle();
  testRectangle();
  testCircle();
}

void testRectangle()
{
  double x = 6.2;
  double y = 1.55;
  point_t point1{x, y};

  double width = 5.34;
  double height = 1.09;
  Shape* rectangle = new Rectangle(point1, width, height);

  std::cout << "Rectangle:\n";
  std::cout << "width is: " << width << '\n';
  std::cout << "height is: " << height << '\n';
  std::cout << "Area is: " << rectangle->getArea() << '\n';
  std::cout << "Position is: " << rectangle->getFrameRect().pos.x << ", " << rectangle->getFrameRect().pos.y << '\n';

  x = 567;
  y = 0.78;
  point_t point2{x, y};
  rectangle->move(point2);
  std::cout << "Rectangle moved on: " << x << ", " << y << '\n';

  delete rectangle;
}

void testCircle()
{
  double x = 7.99;
  double y = 16.83;

  double radius = 123.98;
  Shape* circle = new Circle(x, y, radius);

  std::cout << "\nCircle:\n";
  std::cout << "Radius is: " << radius << '\n';
  std::cout << "Area is: " << circle->getArea() << '\n';
  std::cout << "Position is: " << circle->getFrameRect().pos.x << ", " << circle->getFrameRect().pos.y << '\n';

  x = 0.444;
  y = 0.555;
  circle->move(x, y);
  std::cout << "Circle moved on: " << x << ", " << y << '\n';
  delete circle;
}
