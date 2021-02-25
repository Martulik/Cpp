#include <iostream>
#include "shape.hpp"
#include "circle.hpp"
#include "rectangle.hpp"

namespace d = doroshin;

void move_x(d::Shape& sh, double dx)
{
  sh.move({ dx, 0 }, false);
}

int main()
{
  d::Circle c1({3, 4}, 2);
  std::cout << "Circle: (" << c1.getFrameRect().pos.x << ", " << c1.getFrameRect().pos.y
    << ") area: " << c1.getArea() << std::endl;
  c1.move({-1, 6}, true);
  std::cout << "Circle: (" << c1.getFrameRect().pos.x << ", " << c1.getFrameRect().pos.y
    << ") area: " << c1.getArea() << std::endl;
  move_x(c1, 2);
  std::cout << "Circle: (" << c1.getFrameRect().pos.x << ", " << c1.getFrameRect().pos.y
    << ") area: " << c1.getArea() << std::endl;

  d::Rectangle r1(d::rectangle_t {1, 2, {2, 5}});
  std::cout << "Rectangle: (" << r1.getFrameRect().pos.x << ", " << r1.getFrameRect().pos.y
    << ") area: " << r1.getArea() << std::endl;
  move_x(r1, -4);
  std::cout << "Rectangle: (" << r1.getFrameRect().pos.x << ", " << r1.getFrameRect().pos.y
    << ") area: " << r1.getArea() << std::endl;
  return 0;
}
