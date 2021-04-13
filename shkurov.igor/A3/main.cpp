#include <iostream>

#include "rectangle.hpp"
#include "circle.hpp"
#include "composite-shape.hpp"

void printCoordinates(const shkurov::Shape& figure)
{
  std::cout << figure.getName() << " is now located by ("
            << figure.getX() << ':'
            << figure.getY() << ')' << '\n';
}

int main()
{
  std::cout << "Rectangle test:" << '\n';
  shkurov::point_t begin_pos = {2, 2};
  std::unique_ptr< shkurov::Shape > rect(std::make_unique< shkurov::Rectangle >
    (shkurov::Rectangle(begin_pos, 4, 4)));

  printCoordinates(*rect);

  rect->move(-2, -2);
  printCoordinates(*rect);

  std::cout << "Area of rectangle is: " << rect->getArea() << '\n';

  std::cout << '\n' << "Circle test:" << '\n';
  begin_pos = {-31.2, 9.21};
  std::unique_ptr< shkurov::Shape > circle(std::make_unique< shkurov::Circle >
    (shkurov::Circle(begin_pos, 2)));

  printCoordinates(*circle);

  shkurov::point_t newPos = {2, 2};
  circle->move(newPos);
  printCoordinates(*circle);

  std::cout << "Area of circle is: " << circle->getArea() << "\n\n";

  std::cout << '\n' << "Composite-shape test:" << '\n';
  std::unique_ptr< shkurov::Shape > rect2(std::make_unique< shkurov::Rectangle >
    (shkurov::Rectangle({4, 4}, 4, 4)));

  std::unique_ptr< shkurov::Shape > composite_shape(std::make_unique< shkurov::CompositeShape >
    (shkurov::CompositeShape(std::move(rect), std::move(rect2), std::move(circle))));

  printCoordinates(*composite_shape);

  composite_shape->move(2, -2);
  printCoordinates(*composite_shape);
  std::cout << "Area of composite-shape is: " << composite_shape->getArea() << "\n\n";

  composite_shape->scale(2);
  printCoordinates(*composite_shape);
  std::cout << "Area of composite-shape after scale is: " << composite_shape->getArea() << "\n\n";

  return 0;
}
