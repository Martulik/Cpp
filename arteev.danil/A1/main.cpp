#include <iostream>

#include "circle.hpp"
#include "rectangle.hpp"

void printCircleParameters(Shape* figureCircle)
{
  std::cout << "Circle radius: " <<figureCircle->getFrameRect().height/2 << "\n";
}

void printCircleCoordinates(Shape* figureCircle)
{
  std::cout << "Coordinates of the center of the circle: \n"
    << "X = " << figureCircle->getFrameRect().pos.x << "\t"
    << "Y = " << figureCircle->getFrameRect().pos.y << "\n";
}

void printRectangleParameters(Shape * figureRectangle)
{
  std::cout << "\nRectangle height: " << figureRectangle->getFrameRect().height << "\n";
  std::cout << "Rectangle width: " << figureRectangle->getFrameRect().width << "\n";
  std::cout << "Rectangle area: " << figureRectangle->getArea() << "\n\n";
}

void printRectangleCoordinates(Shape* figureRectangle)
{
  std::cout << "Coordinates of the center of the rectangle: \n"
    << "X = " << figureRectangle->getFrameRect().pos.x << "\t"
    << "Y = " << figureRectangle->getFrameRect().pos.y << "\n";
}

int main()
{  
  Shape* figureCircle = new Circle({ 2, 2 }, 3);
  printCircleParameters(figureCircle);
  printCircleCoordinates(figureCircle);

  point_t pos = { 12, 7 };
  figureCircle->move(pos);
  printCircleCoordinates(figureCircle);

  figureCircle->move(10, 12);
  printCircleCoordinates(figureCircle);

  delete figureCircle;

  pos = { 5,8 };

  Shape* figureRectangle = new Rectangle(10, 12, { 5,5 });
  printRectangleParameters(figureRectangle);
  printRectangleCoordinates(figureRectangle);

  figureRectangle->move(10, 65);
  printRectangleCoordinates(figureRectangle);

  figureRectangle->move(pos);
  printRectangleCoordinates(figureRectangle);

  delete figureRectangle;
}

