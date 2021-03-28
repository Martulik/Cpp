#include <iostream>
#include <cassert>

#include "circle.hpp"
#include "rectangle.hpp"
#include "composite-shape.hpp"

namespace lab = ezerinia;
using shapePtr = std::shared_ptr< lab::Shape >;

void printFrameRectOfShape(const shapePtr shape, std::ostream &out)
{
  out << "height = " << lab::getHeight(*shape) << "  width = " << lab::getWidth(*shape);
  out << " center: x = " << lab::getX(*shape) << ", y = " << lab::getY(*shape) << "\n";
}

int main()
{
  const lab::point_t startPoint{10.0, 10.0};
  const lab::point_t finishPoint{20.0, 20.0};
  const double radius1 = 3.0;
  const double radius2 = 6.0;
  const double width = 2.0;
  const double height = 1.0;
  const double scaleCoef = 2.0;

  lab::CompositeShape composite(std::make_shared< lab::Circle >(radius1, startPoint));

  shapePtr rectangle = std::make_shared< lab::Rectangle >(width, height, startPoint);
  composite.pushBack(rectangle);

  shapePtr circle = std::make_shared< lab::Circle >(radius2, startPoint);
  composite.pushBack(circle);

  for (size_t i = 0; i < composite.size(); i++) {
    printFrameRectOfShape(composite.at(i), std::cout);
    composite.at(i)->move(finishPoint);
    composite.at(i)->scale(scaleCoef);
    printFrameRectOfShape(composite.at(i), std::cout);
  }

  return 0;
}
