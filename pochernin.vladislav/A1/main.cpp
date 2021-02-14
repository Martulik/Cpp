#include <iostream>

#include "base-types.hpp"
#include "shape.hpp"
#include "rectangle.hpp"
#include "circle.hpp"

int main()
{
  point_t posPoint;
  posPoint.x = 0;
  posPoint.y = 0;

  Shape* testRectangle = new Rectangle(50.123, 100.0, {13.10123, 12.20});
  testRectangle->getInfo();
  std::cout << "Area of Rectangle is: " << testRectangle->getArea() << "\n";
  posPoint.x = 111;
  posPoint.y = 222;
  testRectangle->move(posPoint);
  std::cout << "Now pos of Rectangle is (" << testRectangle->getFrameRect().pos.x
            << "; " << testRectangle->getFrameRect().pos.y << ")\n";
  testRectangle->move(9, 8);
  std::cout << "Now pos of Rectangle is (" << testRectangle->getFrameRect().pos.x
            << "; " << testRectangle->getFrameRect().pos.y << ")\n";

  Shape* testCircle = new Circle(13.1235);
  testCircle->getInfo();
  std::cout << "Area of Circle is: " << testCircle->getArea() << "\n";
  posPoint.x = 111;
  posPoint.y = 222;
  testCircle->move(posPoint);
  std::cout << "Now pos of Circle is (" << testCircle->getFrameRect().pos.x
            << "; " << testCircle->getFrameRect().pos.y << ")\n";
  testCircle->move(19, 38);
  std::cout << "Now pos of Circle is (" << testCircle->getFrameRect().pos.x
            << "; " << testCircle->getFrameRect().pos.y << ")\n";

  delete testRectangle;
  delete testCircle;

  return 0;
}
