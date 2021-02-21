#include <iostream>
#include <string>

#include "base-types.hpp"
#include "shape.hpp"
#include "circle.hpp"
#include "rectangle.hpp"


void printFrameRect(Shape *figure);

void printFiguresCenter(const std::string adj,  Shape *figure);

int main()
{
  point_t myPos{ 33.33, 33.33 };
  point_t newPos{ 0.0, 0.0 };
  double width = 1.0;
  double heigth = 2.0;
  Shape * myRectangle = new Rectangle (width,heigth,myPos);
  std::cout << "Print my rectangle's charactiristics\n"
            << "Its wigth: " << myRectangle->getFrameRect().width << "\n"
            << "Its height: " << myRectangle->getFrameRect().height << "\n";
  printFiguresCenter("", myRectangle);
  std::cout << "Its area " << myRectangle->getArea() << "\n";
  printFrameRect(myRectangle);
  std::cout << "Move the rectangle's center to point (0,0)\n";
  myRectangle->move(newPos);
  printFiguresCenter("new", myRectangle);
  std::cout << "Move rectangle's center along x-asix by 1 along the y-asix by 1\n";
  myRectangle->move(1.0, 1.0);
  printFiguresCenter("new", myRectangle);

  double radius = 33.33;
  Shape * myCircle = new Circle(myPos, radius);
  std::cout << "Print my circle's charactiristics\n"
            << "Its radius: " << (myCircle->getFrameRect().width) / 2 << "\n";
  printFiguresCenter("", myCircle);
  std::cout << "Its area " << myCircle->getArea() << "\n";
  std::cout << "Move the circle's center to point (0,0)\n";
  myCircle->move(newPos);
  printFiguresCenter("new", myCircle);
  std::cout << "Move circle's center along x-asix by 1 along the y-asix by 1\n";
  myCircle->move(1.0, 1.0);
  printFiguresCenter("new", myCircle);
  delete myRectangle;
  delete myCircle;
  return 0;
}

void printFrameRect(Shape* figure)
{
  std::cout << "Its frame rectangle's width: " << figure->getFrameRect().width << ", "
            << "height: " << figure->getFrameRect().height << ", "
            << "center's abscissa: " << figure->getFrameRect().pos->x << ", "
            << "centers's ordinate " << figure->getFrameRect().pos->y << "\n";
}

void printFiguresCenter(const std::string adj, Shape* figure)
{
  std::cout << "Its " << adj << " center's abscissa " << figure->getFrameRect().pos->x << "\n"
            << "Its " << adj << " centers's ordinate " << figure->getFrameRect().pos->y << "\n";
}
