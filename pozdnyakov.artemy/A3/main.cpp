#include <iostream>
#include "circle.hpp"
#include "rectangle.hpp"
#include "base-types.hpp"
#include "composite_shape.hpp"

int main()
{
  pozdnyakov::point_t o{ 0, 0 };
  double rad = 10;
  double width = 20;
  double height = 10;
  pozdnyakov::UniqueShape circle(new pozdnyakov::Circle(rad, o));
  pozdnyakov::UniqueShape rect(new pozdnyakov::Rectangle(width, height, o));
  pozdnyakov::UniqueShapes shapes(new pozdnyakov::UniqueShape[2]);
  shapes.get()[0] = std::move(circle);
  shapes.get()[1] = std::move(rect);
  std::cout << shapes.get()[0]->getArea() << '\n';
  pozdnyakov::CompositeShape cshape(std::move(shapes), 2);
  std::cout << "The area of composite shape is " << cshape.getArea() << '\n';
  cshape.scale(2);
  std::cout << "The area of composite shape is " << cshape.getArea() << '\n';
}
