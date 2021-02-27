#include <iostream>
#include "shape.hpp"
#include "circle.hpp"
#include "rectangle.hpp"

void move_x(Shape& sh, double dx)
{
  sh.move({ dx, 0 }, false);
}

int main()
{
  Circle c1({3, 4}, 2);
  std::cout << "Circle: (" << c1.getFrameRect().pos.x << ", " << c1.getFrameRect().pos.y
    << ") area: " << c1.getArea() << std::endl;
  c1.move({-1, 6}, true);
  std::cout << "Circle: (" << c1.getFrameRect().pos.x << ", " << c1.getFrameRect().pos.y
    << ") area: " << c1.getArea() << std::endl;
  move_x(c1, 2);
  std::cout << "Circle: (" << c1.getFrameRect().pos.x << ", " << c1.getFrameRect().pos.y
    << ") area: " << c1.getArea() << std::endl;

  Rectangle r1(rectangle_t {1, 2, {2, 5}});
  std::cout << "Rectangle: (" << r1.getFrameRect().pos.x << ", " << r1.getFrameRect().pos.y
    << ") area: " << r1.getArea() << std::endl;
  move_x(r1, -4);
  std::cout << "Rectangle: (" << r1.getFrameRect().pos.x << ", " << r1.getFrameRect().pos.y
    << ") area: " << r1.getArea() << std::endl;
  return 0;
}
