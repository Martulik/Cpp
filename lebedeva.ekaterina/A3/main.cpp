#include <iostream>
#include "composite-shape.hpp"
#include "circle.hpp"
#include "rectangle.hpp"


namespace lebedeva
{
  void testShape(std::ostream& out, Shape& figure, const point_t& newPos, const double k);
  void testMove(std::ostream& out, Shape& figure, const point_t& newPos);
  void testScale(std::ostream& out, Shape& figure, const double k);
  void printCentre(std::ostream& out, const Shape& figure);
  void printInfo(std::ostream& out, const Shape& figure);
}

using ShapePtr = std::shared_ptr< lebedeva::Shape >;

int main()
{
  lebedeva::point_t pos1 = { 3, 1 };
  lebedeva::point_t pos2 = { 1.17, 2.3 };
  lebedeva::point_t newPos = { 13, 8 };
  double scaleParameter = 5.11;
  ShapePtr rectPtr = std::make_shared< lebedeva::Rectangle >(pos1, 12.2, 2.1);
  ShapePtr circPtr = std::make_shared < lebedeva::Circle >(pos1, 6.2);

  lebedeva::CompositeShape composition
  {
    std::make_shared< lebedeva::Rectangle >(pos2, 3.0, 4.1),
    std::make_shared< lebedeva::Circle >(pos1, 3.24)
  };

  std::cout << "Figure 1.\n";
  lebedeva::testShape(std::cout, *rectPtr, newPos, scaleParameter);
  std::cout << "Figure 2.\n";
  lebedeva::testShape(std::cout, *circPtr, newPos, scaleParameter);
  std::cout << "Figure 3.\n";
  lebedeva::testShape(std::cout, composition, newPos, scaleParameter);

  return 0;
}

void lebedeva::printCentre(std::ostream& out, const Shape& figure)
{
  rectangle_t rect = figure.getFrameRect();
  out << '(' << rect.pos.x;
  out << ", " << rect.pos.y << ')';
}

void lebedeva::printInfo(std::ostream& out, const Shape& figure)
{
  out << "Specific: " << figure.getName() << '\n';
  out << "Centre position is ";
  printCentre(out, figure);
  out << "\nArea: " << figure.getArea();
  rectangle_t rect = figure.getFrameRect();
  out << "\nFrame rectangle: " << rect.width;
  out << " x " << rect.height << '\n';
}

void lebedeva::testShape(std::ostream& out, Shape& figure, const point_t& newPos, const double k)
{
  printInfo(out, figure);
  testMove(out, figure, newPos);
  testScale(out, figure, k);
}

void lebedeva::testMove(std::ostream& out, Shape& figure, const point_t& newPos)
{
  out << "Centre position after moving to point (";
  out << newPos.x << ", " << newPos.y << ") is ";
  figure.move(newPos);
  printCentre(std::cout, figure);
  out << "\nCentre position after moving to point (x + dx, y - dy) is ";
  figure.move(newPos.x, -newPos.y);
  printCentre(std::cout, figure);
  out << "\n";
}

void lebedeva::testScale(std::ostream& out, Shape& figure, const double k)
{
  out << "Area after scale " << k << " times: ";
  figure.scale(k);
  out << figure.getArea() << "\n\n";
}
