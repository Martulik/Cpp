#include <iostream>
#include "circle.hpp"
#include "rectangle.hpp"
#include "base-types.hpp"
int main()
{
  point_t o(0, 0);
  Rectangle rec1(o, 20, 10);
  Rectangle rec2(o, 30, 50);
  Rectangle rec3(o, 13, 21);
  Circle circle1(o, 33);
  Circle circle2(o, 55);
  Circle circle3(o, 53);
  Shape* figures[] = {&rec1, &rec2, &rec3, &circle1, &circle2, &circle3};
  for (int i = 0; i < 6; i++)
  {
    std::cout << "The area of " << i << " figure is: "; 
    std::cout << figures[i]->getArea() << std::endl;
  }
  return 0;
}
