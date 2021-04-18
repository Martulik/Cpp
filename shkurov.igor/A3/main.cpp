#include <iostream>

#include "rectangle.hpp"
#include "circle.hpp"
#include "composite-shape.hpp"

namespace lab = shkurov;

using shapePtr = std::unique_ptr< lab::Shape >;
using Rect = lab::Rectangle;
using Circle = lab::Circle;
using CShape = lab::CompositeShape;

void printCoordinates(const lab::Shape& figure)
{
  std::cout << figure.getName() << " is now located by ("
            << lab::getX(figure) << ':'
            << lab::getY(figure) << ')' << '\n';
}

int main()
{
  std::cout << "Rectangle test:" << '\n';
  lab::point_t begin_pos = {2, 2};
  shapePtr rect(std::make_unique< Rect >(Rect(begin_pos, 4, 4)));

  printCoordinates(*rect);

  rect->move(-2, -2);
  printCoordinates(*rect);

  std::cout << "Area of rectangle is: " << rect->getArea() << '\n';

  std::cout << '\n' << "Circle test:" << '\n';
  begin_pos = {-31.2, 9.21};
  shapePtr circle(std::make_unique< Circle >(Circle(begin_pos, 2)));

  printCoordinates(*circle);

  lab::point_t newPos = {2, 2};
  circle->move(newPos);
  printCoordinates(*circle);

  std::cout << "Area of circle is: " << circle->getArea() << "\n\n";

  std::cout << '\n' << "Composite-shape test:" << '\n';
  shapePtr rect2(std::make_unique< Rect >(Rect({4, 4}, 4, 4)));

  shapePtr composite(std::make_unique< CShape >(CShape(std::move(rect), std::move(rect2), std::move(circle))));

  printCoordinates(*composite);

  composite->move(2, -2);
  printCoordinates(*composite);
  std::cout << "Area of composite-shape is: " << composite->getArea() << "\n\n";

  composite->scale(2);
  printCoordinates(*composite);
  std::cout << "Area of composite-shape after scale is: " << composite->getArea() << "\n\n";

  return 0;
}
