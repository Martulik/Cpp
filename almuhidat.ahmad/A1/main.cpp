#include <iostream>
#include "circle.hpp"
#include "rectangle.hpp"



void ShapeInfo(const Shape* figure)
{
  std::cout << "Height: "
    << figure->getFrameRect().height << "\n" << "Width: "
    << figure->getFrameRect().width <<  "\n" <<"Abscissa of the center: "
    << figure->getFrameRect().pos.x << "\n" << "Ordinate of the center: "
    << figure->getFrameRect().pos.y << "\n";
  std::cout << "\n";
}

int main()
{
  point_t posCircle = { 1.3, 3.7 };
  Shape* circle = new Circle(3, posCircle);
  std::cout << "Testing the circle\n";
  std::cout << "\n";

  std::cout << "The area of a given circle: " << circle->getArea() << "\n";
  std::cout << "Described rectangle of a given circle:\n";
  ShapeInfo(circle);

  point_t newPosCircle = { 2.2, 8 };
  circle->move(newPosCircle);
  std::cout << "Moving to a certain point" << "\n";
  std::cout << "Described rectangle of a circle with a new center: " << "\n";
  ShapeInfo(circle);

  circle->move(6, 9);
  std::cout << "Moving along axes\n";
  std::cout << "Described rectangle of a circle with a new center:\n";
  ShapeInfo(circle);
  delete circle;

  point_t posRectangle = { 6.66, 7.77 };
  Shape* rectangle = new Rectangle(1, 2, posRectangle);
    std::cout << "Testing the rectangle\n";
    std::cout << "\n";

  std::cout << "The area of a given rectangle: " << rectangle->getArea() << "\n";
  std::cout << "Described rectangle of a given rectangle: \n";
  ShapeInfo(rectangle);

  point_t newPosRectangle = { 1.5, 2 };
  rectangle->move(newPosRectangle);
  std::cout << "Moving to a certain point\n";
  std::cout << "Described rectangle of a rectangle with a new center:\n";
  ShapeInfo(rectangle);

  rectangle->move(6, 9);
  std::cout << "Moving along axes\n";
  std::cout << "Described rectangle of a rectangle with a new center:\n";
  ShapeInfo(rectangle);
  delete rectangle;
  return 0;
}
