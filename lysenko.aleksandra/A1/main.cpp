#include <iostream>
#include <string>

#include "base-types.hpp"
#include "shape.hpp"
#include "circle.hpp"
#include "rectangle.hpp"

void testMyFigure(Shape* figure);

void printFrameRect(const Shape* figure);

void printFiguresCenter(const std::string adj, Shape* figure);

void printFigure(const Shape* figure);

int main()
{
  point_t myPos{ 33.33, 33.33 };
  double width = 1.0;
  double heigth = 2.0;
  Shape* myRectangle = new Rectangle(width, heigth, myPos);
  testMyFigure(myRectangle);

  double radius = 33.33;
  Shape* myCircle = new Circle(myPos, radius);
  testMyFigure(myCircle);
  delete myRectangle;
  delete myCircle;
  return 0;
}

void printFrameRect(Shape* figure)
{
  std::cout << "Its frame rectangle's width: " << figure->getFrameRect().width << ", "
            << "height: " << figure->getFrameRect().height << ", "
            << "center's abscissa: " << figure->getFrameRect().pos.x << ", "
            << "centers's ordinate " << figure->getFrameRect().pos.y << "\n";
}

void printFiguresCenter(std::string adj, Shape* figure)
{
  std::cout << "Its " << adj << " center's abscissa " << figure->getFrameRect().pos.x << "\n"
            << "Its " << adj << " centers's ordinate " << figure->getFrameRect().pos.y << "\n";
}

void printFigure(Shape* figure)
{
  std::string typeOfFigure = figure->getName();
  std::cout << "Type of figure:" << typeOfFigure << "\n";
  printFiguresCenter("", figure);
  std::cout << "Its area " << figure->getArea() << "\n";
  printFrameRect(figure);
}

void testMyFigure(Shape* figure)
{
  printFigure(figure);
  point_t newPos{ 0.0, 0.0 };
  std::cout << "Move the figure's center to point (" << newPos.x <<","<< newPos.y<<")\n";
  figure->move(newPos);
  printFiguresCenter("new", figure);
  std::cout << "Move figure's center along x-asix by 1 along the y-asix by 1\n";
  figure->move(1.0, 1.0);
  printFiguresCenter("new", figure);
}
