#include <iostream>
#include <cassert>
#include "circle.hpp"
#include "rectangle.hpp"
#include "composite-shape.hpp"

void printFrameRectOfShape(const std::shared_ptr< ezerinia::Shape > shape, std::ostream &out)
{
  out << "height = " << shape->getFrameRect().height << "  width = "
      << shape->getFrameRect().width;
  out << " center: x = " << shape->getFrameRect().pos.x << ", y = "
      << shape->getFrameRect().pos.y << "\n";
}

void testShape(std::shared_ptr< ezerinia::Shape > compositeShape, std::ostream &out)
{
  out << "Area = " << compositeShape->getArea() << "\n";

  out << "Move in point (1.1, 2.2): ";
  compositeShape->move({1.1, 2.2});
  printFrameRectOfShape(compositeShape, out);

  out << "Abs move x: -1.1, y: +1.0: ";
  compositeShape->move(-1.1, 1.0);
  printFrameRectOfShape(compositeShape, out);

  out << "Scale, k = 3: ";
  compositeShape->scale(3);
  printFrameRectOfShape(compositeShape, out);
}

int main()
{
  ezerinia::CompositeShape composite(std::make_shared< ezerinia::Circle >
                                             (1.0, ezerinia::point_t{1.0, 1.0}));

  std::shared_ptr< ezerinia::Shape > rectangle
          = std::make_shared< ezerinia::Rectangle >(2.0, 82.5, ezerinia::point_t{2.0, 2.0});
  composite.push_back(rectangle);

  std::shared_ptr< ezerinia::Shape > circle
          = std::make_shared< ezerinia::Circle >(5.7, ezerinia::point_t{3.0, -6.0});
  composite.push_back(circle);

  for (std::size_t i = 0; i < composite.size(); i++) {
    composite.at(i)->getArea();
    testShape(composite.at(i), std::cout);
  }

  return 0;
}
