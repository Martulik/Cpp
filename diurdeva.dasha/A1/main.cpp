#include <iostream>
#include "circle.hpp"
#include "rectangle.hpp"

void getInfoFrameRect(Shape *figura)
{
  std::cout << "Bounding rectangle: width = " << figura->getFrameRect().width << ", height = "
            << figura->getFrameRect().height
            << ", center: x = " << figura->getFrameRect().pos.x << ", y = " << figura->getFrameRect().pos.y
            << std::endl;
}

void moveShape(Shape *figura, const double x, const double y)
{
  std::cout << "\nMove the center  to a point: (" << x << ";" << y << ")" << std::endl;
  figura->move({x, y});
  std::cout << "New pos center: x = " << figura->getFrameRect().pos.x << ", y = " << figura->getFrameRect().pos.y
            << std::endl;
  std::cout << "Move the center of the rectangle along the x-axis by " << x << " along the y-axis by " << y
            << std::endl;
  figura->move(x, y);
  std::cout << "New pos center: x = " << figura->getFrameRect().pos.x << ", y = " << figura->getFrameRect().pos.y
            << std::endl;
}

int main()
{
  std::cout << "Rectangle: " << std::endl;
  point_t pointCenterRectangle = {3.5, 4.0};
  Shape *rectangle = new Rectangle(8.0, 5.0, pointCenterRectangle);
  std::cout << "Area is: " << rectangle->getArea() << std::endl;
  getInfoFrameRect(rectangle);
  double x = 3.2;
  double y = 5.4;
  moveShape(rectangle, x, y);
  delete rectangle;

  std::cout << "\nCircle: " << std::endl;
  point_t pointCenterCircle = {1, 4};
  Shape *circle = new Circle(8.0, pointCenterCircle);
  getInfoFrameRect(circle);
  std::cout << "Area is: " << circle->getArea() << std::endl;
  x = 2.7;
  y = 1.5;
  moveShape(circle, x, y);
  delete circle;
}
