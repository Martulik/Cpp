#include <iostream>

#include "rectangle.hpp"
#include "circle.hpp"
#include "composite-shape.hpp"

void printCoordinates(const shkurov::Shape* figure)
{
  std::cout << figure->getName() << " is now located by ("
            << figure->getFrameRect().pos.x << ':'
            << figure->getFrameRect().pos.y << ')' << '\n';
}

int main()
{
  std::cout << "Rectangle test:" << '\n';
  shkurov::point_t begin_pos = {2, 2};
  std::unique_ptr< shkurov::Shape > rect(new shkurov::Rectangle(begin_pos, 4, 4));

  printCoordinates(rect.get());

  rect->move(-2, -2);
  printCoordinates(rect.get());

  std::cout << "Area of rectangle is: " << rect->getArea() << '\n';

  std::cout << '\n' << "Circle test:" << '\n';
  begin_pos = {-31.2, 9.21};
  std::unique_ptr< shkurov::Shape > circle(new shkurov::Circle(begin_pos, 2));

  printCoordinates(circle.get());

  shkurov::point_t new_pos = {2, 2};
  circle->move(new_pos);
  printCoordinates(circle.get());

  std::cout << "Area of circle is: " << circle->getArea() << "\n\n";

  std::cout << '\n' << "Composite-shape test:" << '\n';
  std::unique_ptr< shkurov::Shape > rect2(new shkurov::Rectangle({4, 4}, 4, 4));

  std::unique_ptr< shkurov::Shape > composite_shape(
    new shkurov::CompositeShape(std::move(rect), std::move(rect2), std::move(circle)));

  printCoordinates(composite_shape.get());

  composite_shape->move(2, -2);
  printCoordinates(composite_shape.get());
  std::cout << "Area of composite-shape is: " << composite_shape->getArea() << "\n\n";

  composite_shape->scale(2);
  printCoordinates(composite_shape.get());
  std::cout << "Area of composite-shape after scale is: " << composite_shape->getArea() << "\n\n";

  return 0;
}
