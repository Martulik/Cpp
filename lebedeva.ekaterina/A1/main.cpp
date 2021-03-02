#include <iostream>
#include "circle.hpp"
#include "rectangle.hpp"

void testRectangleClass();
void testCircleClass();
void printCentre(std::ostream& out, Shape* figure);
void printInfo(std::ostream& out, Shape* figure);

int main()
{
  std::cout << "Figure 1.\n";
  testRectangleClass();
  std::cout << "Figure 2.\n";
  testCircleClass();
  return 0;
}

void printCentre(std::ostream& out, Shape* figure)
{
  out << '(' << figure->getFrameRect().pos.x;
  out << ", " << figure->getFrameRect().pos.y << ')';
}
void printInfo(std::ostream& out, Shape* figure)
{
  out << "Specific: " << figure->getName() << '\n';
  out << "Centre position is ";
  printCentre(out, figure);
  out << "\nFrame rectangle: " << figure->getFrameRect().height;
  out << " x " << figure->getFrameRect().width << '\n';
}

void testRectangleClass()
{
  point_t pos = {0, 0};
  Rectangle rect(pos, 2.1, 12.2);
  printInfo(std::cout, &rect);
  std::cout << "Centre position after moving to point (13, 8) is ";
  point_t newPos = {13, 8};
  rect.move(newPos);
  printCentre(std::cout, &rect);
  std::cout << "\nCentre position after moving to point (x+13, y-8) is ";
  rect.move(13, -8);
  printCentre(std::cout, &rect);
  std::cout << "\n\n";
}
void testCircleClass()
{
  point_t pos = {3, 1};
  Circle circ(pos, 6.2);
  printInfo(std::cout, &circ);
  std::cout << "Centre position after moving to point (13, 8) is ";
  point_t newPos = { 13, 8 };
  circ.move(newPos);
  printCentre(std::cout, &circ);
  std::cout << "\nCentre position after moving to point (x+13, y-8) is ";
  circ.move(13, -8);
  printCentre(std::cout, &circ);
  std::cout << "\n\n";
}
