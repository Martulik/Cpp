#include <iostream>
#include "circle.hpp"
#include "rectangle.hpp"

int main()
{
  const point_t point_zero = {0, 0};
  Shape* rect = new Rectangle(5, 10, {0,0});
  std::cout << "Area of rectangle equals to: " << rect->getArea() << std::endl;
  std::cout << "Position before move(): X = "<< rect->getFrameRect().pos.x
            <<" Y = " << rect->getFrameRect().pos.y << std::endl;
  rect->move(2, 3.9);
  std::cout << "Position after move(): X = " << rect->getFrameRect().pos.x
            << " Y = " << rect->getFrameRect().pos.y << std::endl;
  rect->move(point_zero);
  std::cout << "Position after second move(): X = " << rect->getFrameRect().pos.x
            << " Y = " << rect->getFrameRect().pos.y << std::endl;

  Shape* circle = new Circle(3.5, point_zero);
  std::cout << "Area of circle equals to: " << circle->getArea() << std::endl;
  std::cout << "Frame Rectangle width = " << circle->getFrameRect().height << " "
            << " height = "<<circle->getFrameRect().width << std::endl;
  std::cout << "Position before move(): X = " << circle->getFrameRect().pos.x
            << " Y = " << circle->getFrameRect().pos.y << std::endl;
  circle->move(4.9, 8.3);
  std::cout << "Position after move(): X = " << circle->getFrameRect().pos.x
    << " Y = " << circle->getFrameRect().pos.y << std::endl;
  circle->move(point_zero);
  std::cout << "Position after second move(): X = " << circle->getFrameRect().pos.x
    << " Y = " << circle->getFrameRect().pos.y << std::endl;
  delete rect;
  delete circle;
  return 0;
}
