#include <iostream>
#include <memory>

#include "circle.hpp"
#include "composite-shape.hpp"
#include "rectangle.hpp"

void printInfoFrameRect(const std::shared_ptr< diurdeva::Shape > figura)
{
  std::cout << "\n Bounding rectangle: width = " << diurdeva::getWidth(*figura) << ", height = "
            << diurdeva::getHeight(*figura)
            << ", center: x = " << diurdeva::getX(*figura) << ", y = " << diurdeva::getY(*figura);
}

int main()
{
  const diurdeva::point_t pointCenter = {3.5, 4.0};
  const diurdeva::point_t newCenter = {3.0, 2.0};
  const double w = 8.0;
  const double h = 5.0;
  const double radius = 3.0;
  const double radius2 = 2.5;
  const double factor = 2.0;

  diurdeva::CompositeShape compositeShape(std::make_shared< diurdeva::Rectangle >(w, h, pointCenter));
  compositeShape.pushBack(std::make_shared< diurdeva::Circle >(radius, pointCenter));
  compositeShape.pushBack(std::make_shared< diurdeva::Circle >(radius2, pointCenter));

  std::cout << "Area is " << compositeShape.getArea();
  for (size_t i = 0; i < compositeShape.size(); i++) {
    printInfoFrameRect(compositeShape.at(i));
    compositeShape.at(i)->move(newCenter);
    compositeShape.at(i)->scale(factor);
    printInfoFrameRect(compositeShape.at(i));
  }
}
