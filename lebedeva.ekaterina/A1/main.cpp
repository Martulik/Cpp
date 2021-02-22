#include <iostream>
#include "circle.hpp"
#include "rectangle.hpp"

void testRectangleClass();
void testCircleClass();
int main()
{
  try
  {
    testRectangleClass();
    std::cout << '\n';
    testCircleClass();
  }
  catch (std::exception& ex) 
  {
    std::cerr << ex.what();
    exit(1);
  }
  return 0;
}
void testRectangleClass()
{
  std::cout << "Rectangle Class tests\n";
  point_t zero = { 0, 0 };
  Rectangle figure1(zero, 2.1, 12.2);
  std::cout << "Constructor tests\n";
  std::cout << "rectangle 1. " << figure1 << '\n';
  Rectangle figure2(figure1);
  std::cout << "rectangle 2. " << figure2 << '\n';
  point_t centre3 = { -3,1 };
  Rectangle figure3(centre3, 10.0, 5.0);
  std::cout << "rectangle 3. " << figure3 << '\n';
  std::cout << "\nCompare operator test\n";
  std::cout << "rectangle 1 == 2? " << ((figure1 == figure2) ? "yes" : "no") << '\n';
  std::cout << "rectangle 1 != 2? " << ((figure1 != figure2) ? "yes" : "no") << '\n';
  std::cout << "rectangle 1 > 3? " << ((figure1 > figure3) ? "yes" : "no") << '\n';
  std::cout << "rectangle 2 <= 3? " << ((figure2 <= figure3) ? "yes" : "no") << '\n';
  std::cout << "\nGet-methods tests\n";
  std::cout << "height of rectangle 1 = " << figure1.getHeight() << '\n';
  std::cout << "width of rectangle 1 = " << figure1.getWidth() << '\n';
  std::cout << "area of rectangle 3 = " << figure3.getArea() << '\n';
  std::cout << "frame rectangle of rectangle 2 is " << figure2.getFrameRect() << '\n';
  std::cout << "centre of rectangle 1 is in " << figure1.getCentre() << '\n';
  std::cout << "\nCentre moving test\n";
  std::cout << "Moving in certain point\n";
  std::cout << "(before moving) rectangle 1. " << figure1 << '\n';
  std::cout << "move centre to point (13, 8)\n";
  point_t newPos = { 13, 8 };
  figure1.move(newPos);
  std::cout << "(after moving) rectangle 1. " << figure1 << '\n';
  std::cout << "Moving to point (x+dx, x+dy)\n";
  std::cout << "(before moving) rectangle 1. " << figure1 << '\n';
  figure1.move(8.9, 1.2);
  std::cout << "move centre to point (x+8.9, y+1.2)\n";
  std::cout << "(after moving) rectangle 1. " << figure1 << '\n';
  std::cout << "\nSet-methods tests\n";
  std::cout << "height of rectangle 1 was " << figure1.getHeight() << '\n';
  figure1.setHeight(1.6);
  std::cout << "new height of rectangle 1 is " << figure1.getHeight() << '\n';
  std::cout << "width of rectangle 1 was " << figure1.getWidth() << '\n';
  figure1.setWidth(9.17);
  std::cout << "new width of rectangle 1 is " << figure1.getWidth() << '\n';
}
void testCircleClass()
{
  std::cout << "Circle Class tests\n";
  point_t zero = { 0, 0 };
  Circle figure1(zero, 2.1);
  std::cout << "Constructor tests\n";
  std::cout << "circle 1. " << figure1 << '\n';
  Circle figure2(figure1);
  std::cout << "circle 2. " << figure2 << '\n';
  point_t centre3 = { -3,1 };
  Circle figure3(centre3, 10.0);
  std::cout << "circle 3. " << figure3 << '\n';
  std::cout << "\nCompare operator test\n";
  std::cout << "circle 1 == 2? " << ((figure1 == figure2) ? "yes" : "no") << '\n';
  std::cout << "circle 1 != 2? " << ((figure1 != figure2) ? "yes" : "no") << '\n';
  std::cout << "circle 1 > 3? " << ((figure1 > figure3) ? "yes" : "no") << '\n';
  std::cout << "circle 2 <= 3? " << ((figure2 <= figure3) ? "yes" : "no") << '\n';
  std::cout << "\nGet-methods tests\n";
  std::cout << "radius of circle 1 = " << figure1.getRadius() << '\n';
  std::cout << "area of circle 3 = " << figure3.getArea() << '\n';
  std::cout << "frame rectangle of circle 3 is " << figure3.getFrameRect() << '\n';
  std::cout << "centre of circle 1 is in " << figure1.getCentre() << '\n';
  std::cout << "\nCentre moving test\n";
  std::cout << "Moving in certain point\n";
  std::cout << "(before moving) circle 1. " << figure1 << '\n';
  std::cout << "move centre to point (13, 8)\n";
  zero = { 13, 8 };
  figure1.move(zero);
  std::cout << "(after moving) circle 1. " << figure1 << '\n';
  std::cout << "Moving to point (x+dx, x+dy)\n";
  std::cout << "(before moving) circle 1. " << figure1 << '\n';
  figure1.move(8.9, 1.2);
  std::cout << "move centre to point (x+8.9, y+1.2)\n";
  std::cout << "(after moving) circle 1. " << figure1 << '\n';
  std::cout << "\nSet-methods tests\n";
  std::cout << "radius of circle 1 was " << figure1.getRadius() << '\n';
  figure1.setRadius(1.6);
  std::cout << "new radius of circle 1 is " << figure1.getRadius() << '\n';
}