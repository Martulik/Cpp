#include <iostream>
#include "rectangle.hpp"
#include "composite-shape.hpp"
#include "circle.hpp"

void printShapeDescription(const shilyaev::Shape &shape)
{
  std::cout << "Area: " << shape.getArea()
            << ", Width × Height: " << getWidth(shape) << " × " << getHeight(shape)
            << ", Center: " << getX(shape) << ' ' << getY(shape) << '\n';
}

int main()
{
  const shilyaev::point_t startPos{2.0, 2.0};
  const shilyaev::point_t finishPos{-1.0, -1.0};
  const double rectangleWidth = 0.5;
  const double rectangleHeight = 5.0;
  const double radius = 2.0;
  const double scaleFactor = 3.5;
  const size_t arraySize = 3;

  auto shapes = std::make_unique< std::unique_ptr< shilyaev::Shape >[] >(arraySize);
  shapes[0] = std::make_unique< shilyaev::Circle >(radius, startPos);
  shapes[1] = std::make_unique< shilyaev::Rectangle >(rectangleWidth, rectangleHeight, startPos);
  auto compositeShape = std::make_unique< shilyaev::CompositeShape >(shapes[0]->clone());
  compositeShape->pushBack(shapes[1]->clone());
  shapes[2] = std::move(compositeShape);

  for (size_t i = 0; i < arraySize; ++i) {
    printShapeDescription(*shapes[i]);
    shapes[i]->move(finishPos);
    shapes[i]->scale(scaleFactor);
    printShapeDescription(*shapes[i]);
  }
}
