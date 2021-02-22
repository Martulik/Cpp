#include "rectangle.hpp"
#include "circle.hpp"
#include <iostream>

int main()
{
  point_t posCircle = {1.3, 3.7};
  Shape* circle = new Circle(3, posCircle);
  std::cout << "Testing the circle" << std::endl;
  std::cout << std::endl;

  std::cout << "The area of a given circle: " << circle->getArea() << std::endl;
  std::cout << "Described rectangle of a given circle: \n" << "Height: "
            << circle->getFrameRect().height << "\nWidth: "
            << circle->getFrameRect().width << "\nAbscissa of the center: "
            << circle->getFrameRect().pos.x << "\nOrdinate of the center: "
            << circle->getFrameRect().pos.y
            << std::endl;
  std::cout << std::endl;

  point_t newPosCircle = {2.2, 8};
  circle->move(newPosCircle);
  std::cout << "Moving to a certain point" << std::endl;
  std::cout << "Described rectangle of a circle with a new center: \n" << "Height: "
      << circle->getFrameRect().height << "\nWidth: "
      << circle->getFrameRect().width << "\nAbscissa of the center: "
      << circle->getFrameRect().pos.x << "\nOrdinate of the center: "
      << circle->getFrameRect().pos.y
      << std::endl;
  std::cout << std::endl;

  circle->move(6, 9);
  std::cout << "Moving along axes" << std::endl;
  std::cout << "Described rectangle of a circle with a new center: \n" << "Height: "
      << circle->getFrameRect().height << "\nWidth: "
      << circle->getFrameRect().width << "\nAbscissa of the center: "
      << circle->getFrameRect().pos.x << "\nOrdinate of the center: "
      << circle->getFrameRect().pos.y
      << std::endl;
  std::cout << std::endl;
  delete circle;

  point_t posRectangle = {6.66, 7.77};
  Shape* rectangle = new Rectangle(1, 2, posRectangle);
  std::cout << "Testing the rectangle" << std::endl;
  std::cout << std::endl;

  std::cout << "The area of a given rectangle: " << rectangle->getArea() << std::endl;
  std::cout << "Described rectangle of a given rectangle: \n" << "Height: "
      << rectangle->getFrameRect().height << "\nWidth: "
      << rectangle->getFrameRect().width << "\nAbscissa of the center: "
      << rectangle->getFrameRect().pos.x << "\nOrdinate of the center: "
      << rectangle->getFrameRect().pos.y
      << std::endl;
  std::cout << std::endl;

  point_t newPosRectangle = {1.5, 2};
  rectangle->move(newPosRectangle);
  std::cout << "Moving to a certain point" << std::endl;
  std::cout << "Described rectangle of a rectangle with a new center: \n" << "Height: "
      << rectangle->getFrameRect().height << "\nWidth: "
      << rectangle->getFrameRect().width << "\nAbscissa of the center: "
      << rectangle->getFrameRect().pos.x << "\nOrdinate of the center: "
      << rectangle->getFrameRect().pos.y
      << std::endl;
  std::cout << std::endl;

  rectangle->move(6, 9);
  std::cout << "Moving along axes" << std::endl;
  std::cout << "Described rectangle of a rectangle with a new center: \n" << "Height: "
      << rectangle->getFrameRect().height << "\nWidth: "
      << rectangle->getFrameRect().width << "\nAbscissa of the center: "
      << rectangle->getFrameRect().pos.x << "\nOrdinate of the center: "
      << rectangle->getFrameRect().pos.y
      << std::endl;
  std::cout << std::endl;
  delete rectangle;
}
