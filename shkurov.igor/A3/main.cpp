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
  shkurov::Rectangle rect(begin_pos, 4, 4);

  shkurov::Shape* figure = std::addressof(rect);
  printCoordinates(figure);

  figure->move(-2, -2);
  printCoordinates(figure);

  std::cout << "Area of rectangle is: " << figure->getArea() << '\n';

  std::cout << '\n' << "Circle test:" << '\n';
  begin_pos = {-31.2, 9.21};
  shkurov::Circle circle(begin_pos, 2);

  figure = std::addressof(circle);
  printCoordinates(figure);

  shkurov::point_t new_pos = {2, 2};
  figure->move(new_pos);
  printCoordinates(figure);

  std::cout << "Area of circle is: " << figure->getArea() << "\n\n";


  std::cout << '\n' << "Composite-shape test:" << '\n';
  shkurov::Rectangle rect2({4, 4}, 4, 4);
  std::unique_ptr< shkurov::Shape > composite_shape(new shkurov::CompositeShape({&rect, &rect2, &circle}));
  printCoordinates(composite_shape.get());

  composite_shape->move(2, -2);
  printCoordinates(composite_shape.get());
  std::cout << "Area of composite-shape is: " << composite_shape->getArea() << "\n\n";

  composite_shape->scale(2);
  printCoordinates(composite_shape.get());
  std::cout << "Area of composite-shape after scale is: " << composite_shape->getArea() << "\n\n";

  return 0;
}
