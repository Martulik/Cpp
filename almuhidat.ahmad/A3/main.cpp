#include <iostream>
#include "composite-shape.hpp"
#include "rectangle.hpp"
#include "circle.hpp"

namespace almuhidat
{
  void info(const std::shared_ptr <almuhidat::Shape> shp);
}
int main()
{
  const double radius = 12.0;
  const almuhidat::point_t ctr = {4.8, 2.9};
  const double h = 10.9;
  const double w = 5.0;
  const almuhidat::point_t pos = {-2.0, 9.1};
  const almuhidat::point_t newCtr = {4.0, 6.8};
  const double k = 5.0;

  almuhidat::Rectangle rectangle(h, w, pos);
  std::shared_ptr< almuhidat::Shape > testRect = std::make_shared< almuhidat::Rectangle >(rectangle);

  almuhidat::Circle circle(ctr, radius);
  almuhidat::CompositeShape testArray(std::make_shared< almuhidat::Circle >(circle));

  testArray.pushBack(testRect);
  std::cout << "Area: " << testArray.getArea();
  for (size_t i = 0; i < testArray.size(); i++)
  {
     info(testArray.at(i));
     testArray.at(i)->move(newCtr);
     testArray.at(i)->scale(k);
     info(testArray.at(i));
  }
  return 0;
}

void almuhidat::info(std::shared_ptr< almuhidat::Shape > shp)
{
  std::cout << "\nFrame Rectangle: width = " << almuhidat::getWidth(*shp);
  std::cout << "\nheight = " << almuhidat::getHeight(*shp);
  std::cout << "\ncenter: x = " << almuhidat::getX(*shp) << "\ny = " << almuhidat::getY(*shp);
}