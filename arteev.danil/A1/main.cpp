#include <iostream>

#include "circle.hpp"
#include "rectangle.hpp"


int main()
{
  Shape* figureCircle = new Circle(7, { 2, 2 });
  std::cout << "Coordinates of the center of the circle before moving: \n"
  << "X = " << figureCircle->getFrameRect().pos.x << "\t"
  << "Y = " << figureCircle->getFrameRect().pos.y << std::endl;

  point_t pos = { 12, 7 };
  figureCircle->move(pos);
  std::cout << "Coordinates of the center of the circle after moving (first variant): \n"
  << "X = " << figureCircle->getFrameRect().pos.x << "\t"
  << "Y = " << figureCircle->getFrameRect().pos.y << std::endl;

  figureCircle->move(13.2, 56);
  std::cout << "Coordinates of the center of the circle after moving (second variant): \n"
  << "X = " << figureCircle->getFrameRect().pos.x << "\t"
  << "Y = " << figureCircle->getFrameRect().pos.y << std::endl;
  std::cout << "Area of a circle: " << figureCircle->getArea() << std::endl<<std::endl;
  delete figureCircle;

  Shape* figureRectangle = new Rectangle(10, 12, { 5,5 });
  std::cout << "Coordinates of the center of the rectangle before moving: \n"
  << "X = " << figureRectangle->getFrameRect().pos.x << "\t"
  << "Y = " << figureRectangle->getFrameRect().pos.y << std::endl;

  point_t second_pos = { 5, 3 };
  figureRectangle->move(second_pos);
  std::cout << "Coordinates of the center of the rectangle after moving (first variant): \n"
  << "X = " << figureRectangle->getFrameRect().pos.x << "\t"
  << "Y = " << figureRectangle->getFrameRect().pos.y << std::endl;

  figureRectangle->move(12, 7);
  std::cout << "Coordinates of the center of the rectangle after moving (second variant): \n"
  << "X = " << figureRectangle->getFrameRect().pos.x << "\t"
  << "Y = " << figureRectangle->getFrameRect().pos.y << std::endl;
  std::cout << "Area of a rectangle: " << figureRectangle->getArea() << std::endl;
  delete figureRectangle;
}

