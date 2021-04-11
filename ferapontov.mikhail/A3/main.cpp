#include <iostream>
#include "circle.hpp"
#include "rectangle.hpp"
#include "composite-shape.hpp"

namespace fer = ferapontov;
using UniqueShp = std::unique_ptr< fer::Shape > ;

void testArea(fer::Shape& shp)
{
  std::cout << shp.getArea() << '\n';
}

void testMove(fer::Shape& shp, const fer::point_t& pos)
{
  std::cout << "Shape before move: X = "
            << getX(shp) << " Y = " << getY(shp) << '\n';
  shp.move(pos);
  std::cout << "Shape after move: X = "
            << getX(shp) << " Y = " << getY(shp) << '\n';
}

void testScale(fer::Shape& shp, const double k)
{
  std::cout << "Shape before scale \n";
  std::cout << "Width = " << getWidth(shp) << '\n';
  std::cout << "Height = " << getHeight(shp) << '\n';
  std::cout << "Pos: X = " << getX(shp) << " Y = " << getY(shp) << '\n';
  shp.scale(k);
  std::cout << "Shape after scale \n";
  std::cout << "Width = " << getWidth(shp) << '\n';
  std::cout << "Height = " << getHeight(shp) << '\n';
  std::cout << "Pos: X = " << getX(shp) << " Y = " << getY(shp) << '\n';
}

int main()
{
  const fer::point_t point_zero = {0, 0};
  const fer::point_t not_zero = {123, 3};
  UniqueShp rectangle = std::make_unique< fer::Rectangle >(10, 20, not_zero);
  UniqueShp circle = std::make_unique< fer::Circle >(5, point_zero);

  testArea(*rectangle);
  testArea(*circle);

  testMove(*rectangle, not_zero);
  testMove(*circle, not_zero);

  testScale(*rectangle, 4);
  testScale(*circle, 5);

  std::initializer_list< UniqueShp > c{std::move(rectangle), std::move(circle)};
  UniqueShp comp = std::make_unique< fer::CompositeShape >(c);

  testMove(*comp, not_zero);
  testArea(*comp);
  testScale(*comp, 6);
  return 0;
}
