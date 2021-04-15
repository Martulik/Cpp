#include <iostream>
#include "circle.hpp"
#include "rectangle.hpp"
#include "base-types.hpp"
#include "composite-shape.hpp"

int main()
{
  pozdnyakov::point_t o{ 0, 0 };
  double rad = 10;
  double width = 20;
  double height = 10;
  pozdnyakov::UniqueShape circle = std::make_unique<pozdnyakov::Circle>(rad, o);
  pozdnyakov::UniqueShape rect = std::make_unique<pozdnyakov::Rectangle>(width, height, o);
  pozdnyakov::UniqueShapes shapes = std::make_unique<pozdnyakov::UniqueShape[]>(2);
  shapes[0] = std::move(circle);
  shapes[1] = std::move(rect);
  std::cout << shapes[0]->getArea() << '\n';
  pozdnyakov::CompositeShape cshape(std::move(shapes), 2);
  std::cout << "The area of composite shape is " << cshape.getArea() << '\n';
  cshape.scale(2);
  std::cout << "The area of composite shape is " << cshape.getArea() << '\n';
}
