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
  Shape* rectangle = new Rectangle(width, height, point);

  point_t temp1 = rectangle->getFrameRect().pos;
  std::cout << "Rectangle:\n";
  std::cout << "Width is: " << rectangle->getFrameRect().width << '\n';
  std::cout << "Height is: " << rectangle->getFrameRect().height << '\n';
  std::cout << "Area is: " << rectangle->getArea() << '\n';
  std::cout << "Position is: "
            << temp1.x << ", "
            << temp1.y << '\n';

  x = 3.33;
  y = 3.33;
  rectangle->move(x, y);

  std::cout << "Rectangle moved in: "
            << rectangle->getFrameRect().pos.x << ", "
            << rectangle->getFrameRect().pos.y << '\n';

  x = 5.25;
  y = 5.25;

  double radius = 7.77;
  Shape* circle = new Circle(radius, {x, y});

  point_t temp2 = circle->getFrameRect().pos;
  std::cout << "Circle:\n";
  std::cout << "Radius is: " << circle->getFrameRect().width/2 << '\n';
  std::cout << "Area is: " << circle->getArea() << '\n';
  std::cout << "Position is: "
            << temp2.x << ", "
            << temp2.y << '\n';

  x = 7.77;
  y = 7.77;
  point_t point2{x, y};
  circle->move(point2);

  std::cout << "Circle moved in: "
            << temp2.x << ", "
            << temp2.y << '\n';

  delete rectangle;
  delete circle;
}
