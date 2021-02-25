#include <iostream>
#include "shape.hpp"
#include "circle.hpp"
#include "rectangle.hpp"
#include "composite-shape.hpp"

namespace d = doroshin;

void move_x(d::Shape& sh, double dx)
{
  sh.move_rel({ dx, 0 });
}

int main()
{
  d::Circle c1({3, 4}, 2);
  std::cout << "Circle: (" << c1.getFrameRect().pos.x << ", " << c1.getFrameRect().pos.y
    << ") area: " << c1.getArea() << std::endl;
  c1.move_abs({-1, 6});
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

  d::CompositeShape shape { c1, r1 };
  std::cout << "Composite shape: (" << shape.getFrameRect().pos.x << ", " << shape.getFrameRect().pos.y
    << ") width: " << shape.getFrameRect().width << " x height: " << shape.getFrameRect().height
    << std::endl;
  return 0;
}
