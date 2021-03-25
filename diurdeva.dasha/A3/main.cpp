#include "circle.hpp"
#include "composite-shape.hpp"
#include "rectangle.hpp"
#include <iostream>
#include <memory>

bool testScale(diurdeva::Shape *figura, const int index)
{
  double area = figura->getArea();
  figura->scale(index);
  if (area * index * index == figura->getArea()) {
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

void testShape(diurdeva::Shape *figura, const char *nameShape, const diurdeva::point_t newCenter, const int index)
{
  printInfoFrameRect(nameShape, figura);
  testScale(figura, index);
  figura->move(newCenter);
  bool check = ((figura->getFrameRect().pos.x == newCenter.x) && (figura->getFrameRect().pos.y == newCenter.y));
  std::cout << "\nThe move has passed: " << (check ? "right" : "wrong");
  std::cout << "\nThe scale has passed: " << (testScale(figura, index) ? "right" : "wrong") << "\n";
}

int main()
{
  const diurdeva::point_t pointCenter = {3.5, 4.0};
  const diurdeva::point_t newCenter = {3.0, 2.0};
  const double w = 8.0;
  const double h = 5.0;
  const double radius = 3;
  const int scale = 2;

  diurdeva::Shape *rectangle = new diurdeva::Rectangle(w, h, pointCenter);
  testShape(rectangle, "Rectangle", newCenter, scale);
  diurdeva::Shape *circle = new diurdeva::Circle(radius, pointCenter);
  testShape(circle, "Circle", newCenter, scale);
  delete rectangle;
  delete circle;

  diurdeva::CompositeShape compositeShape(std::make_shared<diurdeva::Rectangle>(w, h, pointCenter));
  compositeShape.push_back(std::make_shared<diurdeva::Circle>(radius, pointCenter));
  testShape(&compositeShape, "CompositeShape", newCenter, scale);
}
