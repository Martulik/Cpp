#include <iostream>
#include "rectangle.hpp"
#include "composite-shape.hpp"
#include "circle.hpp"

void printShapeDescription(const shilyaev::Shape &shape)
{
  const shilyaev::rectangle_t frameRect = shape.getFrameRect();
  std::cout << "Area: " << shape.getArea() << ", Width × Height: " << frameRect.width << " × " << frameRect.height
            << ", Center: " << frameRect.pos.x << ' ' << frameRect.pos.y << '\n';
}

int main()
{
  const shilyaev::point_t startPos{2.0, 2.0};
  const shilyaev::point_t finishPos{-1.0, -1.0};
  const double rectangleWidth = 0.5;
  const double rectangleHeight = 5.0;
  const double radius = 2.0;
  const double scaleFactor = 3.5;

  shilyaev::CompositeShape compositeShape(
      std::make_unique< shilyaev::Rectangle >(rectangleWidth, rectangleHeight, startPos));
  compositeShape.pushBack(std::make_unique< shilyaev::Circle >(radius, startPos));
  printShapeDescription(compositeShape.at(0));
  printShapeDescription(compositeShape.at(1));
  printShapeDescription(compositeShape);
  compositeShape.move(finishPos);
  compositeShape.scale(scaleFactor);
  printShapeDescription(compositeShape);
}
