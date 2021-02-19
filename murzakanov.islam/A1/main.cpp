#include <iostream>
#include "circle.hpp"
#include "rectangle.hpp"

int main(){
  Shape* polyRectangle = new Rectangle(1, 2, { 3, 5 });
  std::cout << "Rectangle's width is " << polyRectangle->getFrameRect().width << std::endl;
  std::cout << "Rectangle's height is " << polyRectangle->getFrameRect().height << std::endl;
  std::cout << "Rectangle's area is " << polyRectangle->getArea() << std::endl;
  std::cout << "Rectangle's center is (" << polyRectangle->getFrameRect().pos.x
  << ", " << polyRectangle->getFrameRect().pos.y << ")" << std::endl;

  Shape* polyCircle = new Circle(5.25, { 13, -12 });
  std::cout << "Circle's radius is " << polyCircle->getFrameRect().width / 2 << std::endl;
  std::cout << "Circle's area is " << polyCircle->getArea() << std::endl;
  std::cout << "Circle's center is (" << polyCircle->getFrameRect().pos.x
  << ", " << polyCircle->getFrameRect().pos.y << ")" << std::endl;

  polyCircle->move(5.6, 10.2);
  std::cout << "Circle's center after method move is (" << polyCircle->getFrameRect().pos.x
  << ", " << polyCircle->getFrameRect().pos.y << ")" << std::endl;
  delete polyRectangle;
  delete polyCircle;
  return 0;
}
