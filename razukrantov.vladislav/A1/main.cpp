#include "shape.hpp"
#include "rectangle.hpp"
#include "circle.hpp"
#include <iostream>

int main()
{
  point_t point{ 8.5, 7.5};
  Shape* ownRectangle = new Rectangle(5, 7, point);
  std::cout << "Rectangle width is: " << ownRectangle->getFrameRect().width << std::endl;
  std::cout << "Rectangle height is: " << ownRectangle->getFrameRect().height << std::endl;
  std::cout << "Rectangle area is: " << ownRectangle->getArea() << std::endl;
  std::cout << "Rectangle center is: " << ownRectangle->getFrameRect().pos.x << ", "
  << ownRectangle->getFrameRect().pos.y << std::endl;
  ownRectangle->move(10, 11);
  std::cout << "Rectangle center after move: " << ownRectangle->getFrameRect().pos.x << ", "
  << ownRectangle->getFrameRect().pos.y << std::endl << std::endl;

  Shape* ownCircle = new Circle(8, { 2.5, 3.5 });
  std::cout << "Circle radius is: " << ownCircle->getFrameRect().width / 2 << std::endl;
  std::cout << "Circle area is: " << ownCircle->getArea() << std::endl;
  std::cout << "Circle center is: " << ownCircle->getFrameRect().pos.x << ", " << ownCircle->getFrameRect().pos.y << std::endl;
  point_t newpoint{ 4, 7 };
  ownCircle->move(newpoint);
  std::cout << "Circle center after move " << ownCircle->getFrameRect().pos.x << ", " << ownCircle->getFrameRect().pos.y << std::endl;

  delete ownRectangle;
  delete ownCircle;
}
