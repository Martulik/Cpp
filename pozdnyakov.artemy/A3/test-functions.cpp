#include "test-functions.hpp"
#include "circle.hpp"
#include "rectangle.hpp"

UniqueShape pozdnyakov::makeRect()
{
  const double width = 99.3;
  const double height = 7;
  const pozdnyakov::point_t pos{13, 12};
  UniqueShape shape(new pozdnyakov::Rectangle(width, height, pos));
  return shape;
}

UniqueShape pozdnyakov::makeCircle()
{
  const double rad = 88;
  const pozdnyakov::point_t pos{77, 13};
  UniqueShape shape(new pozdnyakov::Circle(rad, pos));
  return shape;
}

UniqueShape pozdnyakov::makeCompositeShape()
{
  UniqueShapes shapes(new UniqueShape[2]);
  shapes[0] = pozdnyakov::makeCircle();
  shapes[1] = pozdnyakov::makeRect();
  UniqueShape cshape(new CompositeShape(std::move(shapes), 2));
  return cshape;
}
