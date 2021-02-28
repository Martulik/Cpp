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

void getShapeArea(Shape *figura)
{
  std::cout << "Area is: " << figura->getArea() << std::endl;
}

void moveShape(Shape *figura)
{
  double x = 3.2;
  double y = 5.4;
  std::cout << "\nMove the center  to a point: (" << x << ";" << y << ")" << std::endl;
  figura->move({x, y});
  std::cout << "New pos center: x = " << figura->getFrameRect().pos.x << ", y = " << figura->getFrameRect().pos.y
            << std::endl;
  x = 4.1;
  y = 2.2;
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
  getShapeArea(rectangle);
  getInfoFrameRect(rectangle);
  moveShape(rectangle);
  delete rectangle;

  std::cout << "\nCircle: " << std::endl;
  point_t pointCenterCircle = {1, 4};
  Shape *circle = new Circle(8.0, pointCenterCircle);
  getShapeArea(circle);
  getInfoFrameRect(circle);
  moveShape(circle, x, y);
  delete circle;
}
