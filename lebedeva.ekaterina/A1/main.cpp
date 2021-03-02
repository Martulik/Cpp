#include <iostream>
#include "circle.hpp"
#include "rectangle.hpp"

void testShape(Shape* figure);
void printCentre(std::ostream& out, Shape* figure);
void printInfo(std::ostream& out, Shape* figure);

int main()
{
  point_t pos = {3, 1};
  Rectangle rect(pos, 2.1, 12.2);
  Circle circ(pos, 6.2);

  std::cout << "Figure 1.\n";
  testShape(&rect);
  std::cout << "Figure 2.\n";
  testShape(&circ);

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

void testShape(Shape* figure)
{
  printInfo(std::cout, figure);
  std::cout << "Centre position after moving to point (13, 8) is ";
  point_t newPos = {13, 8};
  figure->move(newPos);
  printCentre(std::cout, figure);
  std::cout << "\nCentre position after moving to point (x+13, y-8) is ";
  figure->move(13, -8);
  printCentre(std::cout, figure);
  std::cout << "\n\n";
}
