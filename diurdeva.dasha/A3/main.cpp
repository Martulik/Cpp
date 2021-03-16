#include "circle.hpp"
#include "composite-shape.hpp"
#include "rectangle.hpp"
#include <iostream>
#include <memory>

bool testScale(diurdeva::Shape *figura, const int index)
{
  double oldArea = figura->getArea() * index * index;
  figura->scale(index);
  double newArea = figura->getArea();
  if (oldArea == newArea) {
    return true;
  }
  return false;
}

void printInfoFrameRect(const char *nameShape, const diurdeva::Shape *figura)
{
  std::cout << nameShape << " - Bounding rectangle: width = " << figura->getFrameRect().width << ", height = "
            << figura->getFrameRect().height
            << ", center: x = " << figura->getFrameRect().pos.x << ", y = " << figura->getFrameRect().pos.y
            << "\nArea is: " << figura->getArea();
}

void testShape(diurdeva::Shape *figura, const char *nameShape, const diurdeva::point_t newCenter, const double index)
{
  printInfoFrameRect(nameShape, figura);
  figura->move(newCenter);
  bool check = ((figura->getFrameRect().pos.x == newCenter.x) && (figura->getFrameRect().pos.y == newCenter.y));
  std::cout << "\nThe move has passed: " << (check ? "right" : "wrong");
  std::cout << "\nThe scale has passed: " << (testScale(figura, index) ? "right" : "wrong") << "\n";
}

int main()
{
  const diurdeva::point_t pointCenter = {3.5, 4.0};
  const diurdeva::point_t newCenter = {3.0, 2.0};
  const diurdeva::point_t newCenterOfCompositeShape = {1.0, 5.0};
  const double w = 8.0;
  const double h = 5.0;
  const double radius = 3;
  const double scale = 2.0;

  diurdeva::Shape *rectangle = new diurdeva::Rectangle(w, h, pointCenter);
  testShape(rectangle, "Rectangle", newCenter, scale);
  diurdeva::Shape *circle = new diurdeva::Circle(radius, pointCenter);
  testShape(circle, "Circle", newCenter, scale);

  diurdeva::CompositeShape compositeShape(std::make_shared<diurdeva::Rectangle>(w, h, pointCenter));
  compositeShape.addShape(std::make_shared<diurdeva::Circle>(radius, pointCenter));
  testShape(&compositeShape, "CompositeShape", newCenterOfCompositeShape, scale);
}
