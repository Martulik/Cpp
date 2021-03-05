#include "rectangle.hpp"
#include "circle.hpp"

#include <iostream>

void printCoordinates(const Shape* figure)
{
  std::cout << "Figure is now located by (" << figure->getFrameRect().pos.x
            << ':' << figure->getFrameRect().pos.y << ')' << '\n';
}

int main() {
  std::cout << "Rectangle test:" << '\n';
  point_t begin_pos = {5.5, -3.5};
  Rectangle rect(begin_pos, 6, 8);

  Shape* figure = std::addressof(rect);
  printCoordinates(figure);

  figure->move(-5, -20);
  printCoordinates(figure);

  std::cout << "Area of rectangle is: " << figure->getArea() << '\n';

  std::cout << '\n' << "Circle test:" << '\n';
  begin_pos = {-31.2, 9.21};
  Circle circle(begin_pos, 10);

  figure = std::addressof(circle);
  printCoordinates(figure);

  point_t new_pos = {41.2, -100};
  figure->move(new_pos);
  printCoordinates(figure);

  std::cout << "Area of circle is: " << figure->getArea() << '\n';

  return 0;
}
