#include <iostream>

#include "base-types.hpp"
#include "shape.hpp"
#include "rectangle.hpp"
#include "circle.hpp"

int main()
{
  point_t posPoint;
  posPoint.x_ = 0;
  posPoint.y_ = 0;

  Shape* testRectangle = new Rectangle(50.123, 100.0);
  testRectangle->getInfo();
  std::cout << "Area of Rectangle is: " << testRectangle->getArea() << "\n";
  posPoint.x_ = 111;
  posPoint.y_ = 222;
  testRectangle->move(posPoint);
  std::cout << "Now pos of Rectangle is (" << testRectangle->getFrameRect().pos_.x_
            << "; " << testRectangle->getFrameRect().pos_.y_ << ")\n";
  testRectangle->move(9, 8);
  std::cout << "Now pos of Rectangle is (" << testRectangle->getFrameRect().pos_.x_
            << "; " << testRectangle->getFrameRect().pos_.y_ << ")\n";

  Shape* testCircle = new Circle(13.1235);
  testCircle->getInfo();
  std::cout << "Area of Circle is: " << testCircle->getArea() << "\n";
  posPoint.x_ = 111;
  posPoint.y_ = 222;
  testCircle->move(posPoint);
  std::cout << "Now pos of Circle is (" << testCircle->getFrameRect().pos_.x_
            << "; " << testCircle->getFrameRect().pos_.y_ << ")\n";
  testCircle->move(19, 38);
  std::cout << "Now pos of Circle is (" << testCircle->getFrameRect().pos_.x_
            << "; " << testCircle->getFrameRect().pos_.y_ << ")\n";

  delete testRectangle;
  delete testCircle;

  return 0;
}
