#include "test-functions.hpp"
#include "rectangle.hpp"
#include "circle.hpp"

pozdnyakov::UniqueShape pozdnyakov::makeRect()
{
  const double width = 99.3;
  const double height = 7;
  const pozdnyakov::point_t pos{ 13, 12 };
  pozdnyakov::UniqueShape shape(new pozdnyakov::Rectangle(width, height, pos));
  return shape;
}

pozdnyakov::UniqueShape pozdnyakov::makeCircle()
{
  const double rad = 88;
  const pozdnyakov::point_t pos{ 77, 13 };
  pozdnyakov::UniqueShape shape(new pozdnyakov::Circle(rad, pos));
  return shape;
}

pozdnyakov::UniqueShape pozdnyakov::makeCompositeShape()
{
  pozdnyakov::UniqueShapes shapes(new UniqueShape[2]);
  shapes[0] = pozdnyakov::makeCircle();
  shapes[1] = pozdnyakov::makeRect();
  pozdnyakov::UniqueShape cshape(new pozdnyakov::CompositeShape(std::move(shapes), 2));
  return cshape;
}
