#include <iostream>
#include "circle.hpp"
#include "rectangle.hpp"

void printInfoFrameRect(const char *nameShape, const Shape *figura)
{
  std::cout << nameShape << " - Bounding rectangle: width = " << figura->getFrameRect().width << ", height = "
            << figura->getFrameRect().height
            << ", center: x = " << figura->getFrameRect().pos.x << ", y = " << figura->getFrameRect().pos.y
            << "\nArea is: " << figura->getArea() << std::endl;
}

void checkPosition(const Shape *figura, const point_t checkCenter)
{
  bool check = ((figura->getFrameRect().pos.x == checkCenter.x) && (figura->getFrameRect().pos.y == checkCenter.y));
  std::cout << "The move has passed: " << (check ? "right" : "wrong") << std::endl;
}

void moveShape(Shape *figura, const point_t newCenter, bool flag)
{
  if (flag) {
    figura->move(newCenter);
  } else {
    figura->move(newCenter.x, newCenter.y);
  }
}

int main()
{
  const point_t pointCenter = {3.5, 4.0};
  const point_t newCenter = {3.3, 4.6};
  const point_t checkCenterForTranslationAlongTheAxis = {6.8, 8.6};
  const double w = 8.0;
  const double h = 5.0;
  const double radius = 3.2;

  Shape *rectangle = new Rectangle(w, h, pointCenterRectangle);
  printInfoFrameRect("Rectangle", rectangle);
  moveShape(rectangle, newCenter, true);
  checkPosition(rectangle, newCenter);
  delete rectangle;

  Shape *circle = new Circle(radius, pointCenter);
  printInfoFrameRect("Circle", circle);
  moveShape(circle, newCenter, false);
  checkPosition(circle, checkCenterForTranslationAlongTheAxis);
  delete circle;
}
