#include <iostream>
#include "circle.hpp"
#include "rectangle.hpp"

void printInfoFrameRect(const char *nameShape, const Shape *figura)
{
  std::cout << nameShape << " - Bounding rectangle: width = " << figura->getFrameRect().width << ", height = "
            << figura->getFrameRect().height
            << ", center: x = " << figura->getFrameRect().pos.x << ", y = " << figura->getFrameRect().pos.y
            << "\nArea is: " << figura->getArea();
}

void testShape(Shape *figura, const char *nameShape, const point_t newCenter)
{
  printInfoFrameRect(nameShape, figura);
  figura->move(newCenter);
  bool check = ((figura->getFrameRect().pos.x == newCenter.x) && (figura->getFrameRect().pos.y == newCenter.y));
  std::cout << "\nThe move has passed: " << (check ? "right" : "wrong") << "\n";
}

int main()
{
  const point_t pointCenter = {3.5, 4.0};
  const point_t newCenter = {3.3, 4.6};
  const double w = 8.0;
  const double h = 5.0;
  const double radius = 3.2;

  Shape *rectangle = new Rectangle(w, h, pointCenter);
  testShape(rectangle, "Rectangle", newCenter);
  delete rectangle;

  Shape *circle = new Circle(radius, pointCenter);
  testShape(circle, "Circle", newCenter);
  delete circle;
}
