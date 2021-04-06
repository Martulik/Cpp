#include <iostream>
#include "composite-shape.hpp"
#include "circle.hpp"
#include "rectangle.hpp"


namespace lebedeva
{
  void testShape(Shape& figure, const point_t& newPos, const double k);
  void testMove(Shape& figure, const point_t& newPos);
  void testScale(Shape& figure, const double k);
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
  lebedeva::testShape(*rectPtr, newPos, scaleParameter);
  std::cout << "Figure 2.\n";
  lebedeva::testShape(*circPtr, newPos, scaleParameter);
  std::cout << "Figure 3.\n";
  lebedeva::testShape(composition, newPos, scaleParameter);

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

void lebedeva::testShape(Shape& figure, const point_t& newPos, const double k)
{
  printInfo(std::cout, figure);
  testMove(figure, newPos);
  testScale(figure, k);
}

void lebedeva::testMove(Shape& figure, const point_t& newPos)
{
  std::cout << "Centre position after moving to point (";
  std::cout << newPos.x << ", " << newPos.y << ") is ";
  figure.move(newPos);
  printCentre(std::cout, figure);
  std::cout << "\nCentre position after moving to point (x + dx, y - dy) is ";
  figure.move(newPos.x, -newPos.y);
  printCentre(std::cout, figure);
  std::cout << "\n";
}

void lebedeva::testScale(Shape& figure, const double k)
{
  std::cout << "Area after scale " << k << " times: ";
  figure.scale(k);
  std::cout << figure.getArea() << "\n\n";
}
