#include <iostream>

#include "circle.hpp"
#include "rectangle.hpp"


int main()
{
  Shape* figureCircle = new Circle({ 2, 2 }, 3);
  std::cout << "Coordinates of the center of the circle before moving: \n"
  << "X = " << figureCircle->getFrameRect().pos.x << "\t"
  << "Y = " << figureCircle->getFrameRect().pos.y << "\n";

  point_t pos = { 12, 7 };
  figureCircle->move(pos);
  std::cout << "Coordinates of the center of the circle after moving (first variant): \n"
  << "X = " << figureCircle->getFrameRect().pos.x << "\t"
  << "Y = " << figureCircle->getFrameRect().pos.y << "\n";

  figureCircle->move(10, 12);
  std::cout << "Coordinates of the center of the circle after moving (second variant): \n"
  << "X = " << figureCircle->getFrameRect().pos.x << "\t"
  << "Y = " << figureCircle->getFrameRect().pos.y << "\n";
  std::cout << "Area of a circle: " << figureCircle->getArea() << "\n\n";
  delete figureCircle;

  Shape* figureRectangle = new Rectangle(10, 12, { 5,5 });
  std::cout << "Rectangle height: " << figureRectangle->getFrameRect().height<< "\n";
  std::cout << "Rectangle width: " << figureRectangle->getFrameRect().width<< "\n";
  std::cout << "Rectangle area: "<< figureRectangle->getArea()<< "\n";
  delete figureRectangle;
}

