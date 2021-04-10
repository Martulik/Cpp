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
  UniqueShp rectangle(new fer::Rectangle(10, 20, {23, 4}));
  UniqueShp circle(new fer::Circle(5, point_zero));

  fer::Circle circ(5, point_zero);
  fer::Rectangle rect(10, 20, {23, 4});
  UniqueShp comp(new fer::CompositeShape({std::addressof(circ), std::addressof(rect)}));

  testArea(*rectangle);
  testArea(*circle);
  testArea(*comp);

  testMove(*rectangle, not_zero);
  testMove(*circle, not_zero);
  testMove(*comp, not_zero);

  testScale(*rectangle, 4);
  testScale(*circle, 5);
  testScale(*comp, 6);
  return 0;
}
