#include <iostream>

#include "base-types.hpp"
#include "shape.hpp"
#include "rectangle.hpp"
#include "circle.hpp"

void showFrameRect(Shape* shape);

int main()
{
  Shape* testRectangle = new Rectangle(50.123, 100.0, {13.10123, 12.20});
  std::cout << "\nRectangle:\n";
  showFrameRect(testRectangle);
  std::cout << "Area of Rectangle is: " << testRectangle->getArea() << "\n";
  point_t posPoint = {111.0, 222.0};
  testRectangle->move(posPoint);
  std::cout << "Now pos of Rectangle is (" << testRectangle->getFrameRect().pos.x
            << "; " << testRectangle->getFrameRect().pos.y << ")\n";
  testRectangle->move(9.0, 8.0);
  std::cout << "Now pos of Rectangle is (" << testRectangle->getFrameRect().pos.x
            << "; " << testRectangle->getFrameRect().pos.y << ")\n";

  Shape* testCircle = new Circle(13.1235, {0.0, 0.0});
  std::cout << "\nCircle:\n";
  showFrameRect(testCircle);
  std::cout << "Area of Circle is: " << testCircle->getArea() << "\n";
  posPoint = {111.0, 222.0};
  testCircle->move(posPoint);
  std::cout << "Now pos of Circle is (" << testCircle->getFrameRect().pos.x
            << "; " << testCircle->getFrameRect().pos.y << ")\n";
  testCircle->move(19.0, 38.0);
  std::cout << "Now pos of Circle is (" << testCircle->getFrameRect().pos.x
            << "; " << testCircle->getFrameRect().pos.y << ")\n";

  delete testRectangle;
  delete testCircle;

  return 0;
}

void showFrameRect(Shape* shape)
{
  std::cout << "-------------------------------------------\n";
  std::cout << "width: " << shape->getFrameRect().width << "\n";
  std::cout << "height: " << shape->getFrameRect().height << "\n";
  std::cout << "pos: " << "(" << shape->getFrameRect().pos.x
            << "; " << shape->getFrameRect().pos.y << ")\n";
  std::cout << "-------------------------------------------\n";
}
