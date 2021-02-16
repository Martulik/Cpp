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

int main()
{
  std::cout << "Rectangle: " << std::endl;
  point_t pointCenterRectangle = {3.5, 4.0};
  Shape *rectangle = new Rectangle(8.0, 5.0, pointCenterRectangle);
  std::cout << "Area is: " << rectangle->getArea() << std::endl;
  std::cout << "\nMove the center of the rectangle to a point (5.0, 3.1):\n";
  point_t newCenterRectangle = {5.0, 3.1};
  rectangle->move(newCenterRectangle);
  getInfoFrameRect(rectangle);
  std::cout << "\nMove the center of the rectangle along the x-axis by 2 along the y-axis by 1:\n";
  rectangle->move(2, 1);
  getInfoFrameRect(rectangle);
  delete rectangle;

  std::cout << "\nCircle: " << std::endl;
  point_t PointCenterCircle = {1, 4};
  Shape *circle = new Circle(8.0, pointCenterRectangle);
  std::cout << "Area is: " << circle->getArea() << std::endl;
  std::cout << "\nMove the center of the  circle to a point (9, 8):\n";
  point_t newCenterCircle = {9, 8};
  circle->move(newCenterCircle);
  getInfoFrameRect(circle);
  std::cout << "\nMove the center of the rectangle along the x-axis by 2 along the y-axis by 1:\n";
  circle->move(2, 1);
  getInfoFrameRect(circle);
  delete circle;
}
