#include "base-types.hpp"
#include "circle.hpp"
#include "composite-shape.hpp"
#include "rectangle.hpp"
#include <iostream>

namespace poz = pozdnyakov;

int main()
{
  try
  {
    poz::point_t o{0, 0};
    double rad = 10;
    double width = 20;
    double height = 10;
    UniqueShape circle = std::make_unique< poz::Circle >(rad, o);
    UniqueShape rect = std::make_unique< poz::Rectangle >(width, height, o);
    UniqueShapes shapes = std::make_unique< UniqueShape[] >(2);
    shapes[0] = std::move(circle);
    shapes[1] = std::move(rect);
    std::cout << shapes[0]->getArea() << '\n';
    poz::CompositeShape cshape(std::move(shapes), 2);
    std::cout << "The area of composite shape is " << cshape.getArea() << '\n';
    cshape.scale(2);
    std::cout << "The area of composite shape is " << cshape.getArea() << '\n';
  }
  catch(...)
  {
    return -1;
  }
  return 0;
}
