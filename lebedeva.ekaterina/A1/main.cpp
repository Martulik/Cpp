#include <iostream>
#include "circle.hpp"
#include "rectangle.hpp"

void testShape(Shape& figure, const point_t& changePos);
void printCentre(std::ostream& out, const Shape& figure);
void printInfo(std::ostream& out, const Shape& figure);

int main()
{
  point_t pos = {3, 1};
  point_t newPos = {13, 8};
  Shape * rectPtr = new Rectangle(pos, 12.2, 2.1);
  Shape * circPtr = new Circle(pos, 6.2);

  std::cout << "Figure 1.\n";
  testShape(*rectPtr, newPos);
  std::cout << "Figure 2.\n";
  testShape(*circPtr, newPos);

  delete rectPtr;
  rectPtr = nullptr;
  delete circPtr;
  circPtr = nullptr;

  return 0;
}

void printCentre(std::ostream& out, const Shape& figure)
{
  out << '(' << figure.getFrameRect().pos.x;
  out << ", " << figure.getFrameRect().pos.y << ')';
}

void printInfo(std::ostream& out, const Shape& figure)
{
  out << "Specific: " << figure.getName() << '\n';
  out << "Centre position is ";
  printCentre(out, figure);
  out << "\nArea: " << figure.getArea();
  out << "\nFrame rectangle: " << figure.getFrameRect().width;
  out << " x " << figure.getFrameRect().height << '\n';
}

void testShape(Shape& figure, const point_t& newPos)
{
  printInfo(std::cout, figure);
  std::cout << "Centre position after moving to point (";
  std::cout << newPos.x << ", " << newPos.y << ") is ";
  figure.move(newPos);
  printCentre(std::cout, figure);
  std::cout << "\nCentre position after moving to point (x + dx, y - dy) is ";
  figure.move(newPos.x, -newPos.y);
  printCentre(std::cout, figure);
  std::cout << "\n\n";
}
