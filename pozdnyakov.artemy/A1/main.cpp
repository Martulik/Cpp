#include <iostream>
#include "circle.hpp"
#include "rectangle.hpp"
#include "base-types.hpp"

int main()
{
  point_t o{ 0, 0 };
  double rad = 10;
  double width = 20;
  double height = 10;
  Circle * circle = new Circle(rad, o);
  Rectangle * rec = new Rectangle(width, height, o);
  Shape * shapes[] = { circle, rec };
  for (int i = 0; i < 2; i++)
  {
    std::cout << "The area of " << i << " figure is " << shapes[i]->getArea() << '\n';
  }
  delete circle;
  delete rec;
}
