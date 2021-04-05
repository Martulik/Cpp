#include <iostream>

#include "composite-shape.hpp"
#include "rectangle.hpp"
#include "circle.hpp"

void info(const std::shared_ptr< ivanova::Shape > shp);

int main()
{
  const double radius = 12.0;
  const ivanova::point_t ctr = {4.8, 2.9};
  const double h = 10.9;
  const double w = 5.0;
  const ivanova::point_t pos = {-2.0, 9.1};
  const ivanova::point_t newCtr = {4.0, 6.8};
  const double k = 5.0;

  ivanova::Rectangle rectangle(h, w, pos);
  std::shared_ptr< ivanova::Shape > testRect = std::make_shared< ivanova::Rectangle >(rectangle);

  ivanova::Circle circle(ctr, radius);
  ivanova::CompositeShape testArray(std::make_shared< ivanova::Circle >(circle));

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

void info(std::shared_ptr< ivanova::Shape > shp)
{
  std::cout << "\nFrame Rectangle: width = " << ivanova::getWidth(*shp);
  std::cout << "\nheight = " << ivanova::getHeight(*shp);
  std::cout << "\ncenter: x = " << ivanova::getX(*shp) << "\ny = " << ivanova::getY(*shp);
}
