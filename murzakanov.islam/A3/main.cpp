#include <iostream>
#include "circle.hpp"
#include "rectangle.hpp"
#include "composite-shape.hpp"

namespace mur = murzakanov;
using RectPtr = std::shared_ptr< mur::Rectangle >;
using CirclePtr = std::shared_ptr< mur::Circle >;
using CmpShpPtr = std::shared_ptr< mur::CompositeShape >;

void print(std::ostream& out, const murzakanov::Shape::ShapePtr shp)
{
  out << "Shape:\n" <<"::Position: " << "(" << shp->getX()
      << ", " << shp->getY() << ")\n";
  out << "Width of frame rectangle: " << shp->getWidth() << "\n"
      << "Height of frame rectangle: " << shp->getHeight() << "\n";
  out << "Specific: " << shp->getName() << "\n\n";
}

int main()
{
  double width = 2.0,
         height = 3.0,
         radius = 1.766;
  mur::point_t pos{1, 2};
  RectPtr polyRectangle(std::make_shared< mur::Rectangle >(width, height, pos));
  CirclePtr polyCircle(std::make_shared< mur::Circle >(radius, pos));
  print(std::cout, polyRectangle);
  print(std::cout, polyCircle);

  mur::point_t point({ 15, 23 });
  polyRectangle->move(point);
  std::cout << "Rectangle's info after move\n";
  print(std::cout, polyRectangle);
  polyRectangle->scale(2.5);
  std::cout << "Rectangle's info after scale\n";
  print(std::cout, polyRectangle);
  polyCircle->move(point.x, point.y);
  std::cout << "Circle's info after move\n";
  print(std::cout, polyCircle);

  CmpShpPtr polyCmpShp(std::make_shared< mur::CompositeShape >(polyCircle));
  polyCmpShp->addShape(polyRectangle);
  print(std::cout, polyCmpShp);
  polyCmpShp->scale(2);
  std::cout << "Composite shape's info after scale\n";
  print(std::cout, polyCmpShp);
  return 0;
}
