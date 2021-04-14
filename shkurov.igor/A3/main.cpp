#include <iostream>

#include "rectangle.hpp"
#include "circle.hpp"
#include "composite-shape.hpp"

namespace ss = shkurov;

using std::make_unique;
using std::unique_ptr;

using shapePtr = unique_ptr < ss::Shape >;

void printCoordinates(const ss::Shape& figure)
{
  std::cout << figure.getName() << " is now located by ("
            << ss::getX(figure) << ':'
            << ss::getY(figure) << ')' << '\n';
}

int main()
{
  std::cout << "Rectangle test:" << '\n';
  ss::point_t begin_pos = {2, 2};
  shapePtr rect(make_unique< Rect > (Rect(begin_pos, 4, 4)));

  printCoordinates(*rect);

  rect->move(-2, -2);
  printCoordinates(*rect);

  std::cout << "Area of rectangle is: " << rect->getArea() << '\n';

  std::cout << '\n' << "Circle test:" << '\n';
  begin_pos = {-31.2, 9.21};
  shapePtr circle(make_unique< Circle > (Circle(begin_pos, 2)));

  printCoordinates(*circle);

  ss::point_t newPos = {2, 2};
  circle->move(newPos);
  printCoordinates(*circle);

  std::cout << "Area of circle is: " << circle->getArea() << "\n\n";

  std::cout << '\n' << "Composite-shape test:" << '\n';
  shapePtr rect2(make_unique< Rect >
    (Rect({4, 4}, 4, 4)));

  shapePtr composite(make_unique< CShape > (CShape(std::move(rect), std::move(rect2), std::move(circle))));

  printCoordinates(*composite);

  composite->move(2, -2);
  printCoordinates(*composite);
  std::cout << "Area of composite-shape is: " << composite->getArea() << "\n\n";

  composite->scale(2);
  printCoordinates(*composite);
  std::cout << "Area of composite-shape after scale is: " << composite->getArea() << "\n\n";

  return 0;
}
