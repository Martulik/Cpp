#include <iostream>
#include "shape.hpp"
#include "rectangle.hpp"
#include "circle.hpp"
#include "composite-shape.hpp"

namespace razukrantov
{
  void printFrameRect(const std::shared_ptr< razukrantov::Shape > shape, std::ostream& out);
}

int main()
{
  const razukrantov::point_t point{ 8.5, 7.5 };
  const razukrantov::point_t point2{ 17.0, 15.0 };
  const double width = 2.0;
  const double height = 3.0;
  const double radius = 4.0;
  const double radius2 = 5.0;
  const double coef = 2.0;

  razukrantov::CompositeShape compositeShape(std::make_shared< razukrantov::Circle >(radius, point));
  compositeShape.pushBack(std::make_shared< razukrantov::Rectangle >(width, height, point));
  compositeShape.pushBack(std::make_shared< razukrantov::Circle >(radius2, point));

  for (size_t i = 0; i < compositeShape.size(); i++)
  {
    printFrameRect(compositeShape.at(i), std::cout);
    compositeShape.at(i)->move(point2);
    compositeShape.at(i)->scale(coef);
    printFrameRect(compositeShape.at(i), std::cout);
  }
}

void razukrantov::printFrameRect(const std::shared_ptr< razukrantov::Shape > shape, std::ostream& out)
{
  out << "width is: " << razukrantov::getWidth(*shape) << "\n";
  out << "height is: " << razukrantov::getHeight(*shape) << "\n";
  out << "center is: " << razukrantov::getX(*shape) << "; " << razukrantov::getY(*shape) << "\n";
}
