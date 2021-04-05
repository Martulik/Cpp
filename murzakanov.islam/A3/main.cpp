#include <iostream>
#include "circle.hpp"
#include "rectangle.hpp"
#include "composite-shape.hpp"

namespace mur = murzakanov;
namespace murzakanov
{
  void print(std::ostream& out, const murzakanov::Shape::ShapePtr shp)
  {
    out << "Shape:\n" <<"::Position: " << "(" << getX(shp)
        << ", " << getY(shp) << ")\n";
    out << "Width of frame rectangle: " << getWidth(shp) << "\n"
        << "Height of frame rectangle: " << getHeight(shp) << "\n";
    out << "Specific: " << shp->getName() << "\n\n";
  }
}
int main()
{
  using CmpShpPtr = std::shared_ptr< mur::CompositeShape >;

  const double width = 2.0;
  const double height = 3.0;
  const double radius = 1.766;
  const double dx = 32;
  const double dy = 13;
  mur::point_t posRect{1, 2};
  mur::point_t posCircle{-5.1, 7.13};
  const int size = 3;
  mur::CompositeShape::ArrayType shapes = std::make_unique< mur::Shape::ShapePtr[] >(size);
  shapes[0] = std::make_shared< mur::Rectangle >(width, height, posRect);
  shapes[1] = std::make_shared< mur::Circle >(radius, posCircle);
  CmpShpPtr cmpShp(std::make_shared< mur::CompositeShape >(shapes[0]));
  cmpShp->addShape(shapes[1]);
  shapes[2] = cmpShp;

  std::cout << "Shape's info before scale\n";
  for (int i = 0; i < size; i++)
  {
    mur::print(std::cout, shapes[i]);
  }
  std::cout << "\n\nShape's info after scale\n\n";
  for (int i = 0; i < size; i++)
  {
    shapes[i]->scale(2);
    mur::print(std::cout, shapes[i]);
  }
  std::cout << "Shape's info before move\n";
  for (int i = 0; i < size; i++)
  {
    mur::print(std::cout, shapes[i]);
  }
  std::cout << "\n\nShape's info after move\n\n";
  for (int i = 0; i < size; i++)
  {
    shapes[i]->move(dx, dy);
    mur::print(std::cout, shapes[i]);
  }
  return 0;
}
