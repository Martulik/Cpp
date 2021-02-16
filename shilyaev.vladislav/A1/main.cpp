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
  Rectangle rectangle(0.5, 5.0, point_t{2.0, 2.0});
  Circle circle(2.0, point_t{0.5, -1.5});
  printShapeDescription(rectangle);
  printShapeDescription(circle);
  rectangle.move(4.0, -4.0);
  circle.move(point_t{-1.0, -2.0});
  std::cout << "After moving:\n";
  printShapeDescription(rectangle);
  printShapeDescription(circle);
}
