#include <iostream>
#include "shape.hpp"
#include "rectangle.hpp"
#include "circle.hpp"

void printShapeDescription(const Shape &shape)
{
  const rectangle_t frameRect = shape.getFrameRect();
  std::cout << "Area: " << shape.getArea() << ", Width × Height: " << frameRect.width << " × " << frameRect.height
            << ", Center: " << frameRect.pos.x << ' ' << frameRect.pos.y << '\n';
}

int main()
{
  const point_t startPos{2.0, 2.0};
  const point_t finishPos{-1.0, -1.0};
  const double rectangleWidth = 0.5;
  const double rectangleHeight = 5.0;
  const double radius = 2.0;
  const double rectangleDx = 4.0;
  const double rectangleDy = -4.0;

  Rectangle rectangle(rectangleWidth, rectangleHeight, startPos);
  Circle circle(radius, startPos);
  printShapeDescription(rectangle);
  printShapeDescription(circle);
  rectangle.move(rectangleDx, rectangleDy);
  circle.move(finishPos);
  std::cout << "After moving:\n";
  printShapeDescription(rectangle);
  printShapeDescription(circle);
}
