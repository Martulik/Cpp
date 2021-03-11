#include <iostream>

#include "shape.hpp"
#include "rectangle.hpp"
#include "circle.hpp"

void printCoordinates(const Shape* figure);

int main()
{
  std::cout << "Rectangle :\n";

  Shape* polyRectangle = new Rectangle(5, 5, {5, 5});
  printCoordinates(polyRectangle);

  polyRectangle->move(6, 6);
  printCoordinates(polyRectangle);

  std::cout << "Area of rectangle is: " << polyRectangle->getArea() << '\n';

  delete polyRectangle;

  std::cout << "Circle :\n";

  Shape* polyCircle = new Circle(5, {5, 5});
  printCoordinates(polyCircle);

  polyCircle->move({6, 6});
  printCoordinates(polyCircle);

  std::cout << "Area of circle is: " << polyCircle->getArea() << '\n';

  delete polyCircle;

  return 0;
}

void printCoordinates(const Shape* figure)
{
  std::cout << "Now the figure is located (" << figure->getFrameRect().pos.x
            << ", " << figure->getFrameRect().pos.y << ")\n";
}

