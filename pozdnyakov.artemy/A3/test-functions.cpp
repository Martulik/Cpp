#include "test-functions.hpp"
#include "circle.hpp"
#include "rectangle.hpp"

void testScale(UniqueShape shape)
{
  double area = shape->getArea();
  double k1 = 0.2;
  shape->scale(k1);
  BOOST_CHECK_CLOSE(shape->getArea(), area * k1 * k1, delta);
  area = shape->getArea();
  double k2 = 10;
  shape->scale(k2);
  BOOST_CHECK_CLOSE(shape->getArea(), area * k2 * k2, delta);
}

void testMove(UniqueShape shape)
{
  double prevX = shape->getFrameRect().pos.x;
  double prevY = shape->getFrameRect().pos.y;
  double dx = 86;
  double dy = -95;
  shape->move(dx, dy);
  BOOST_CHECK_CLOSE(shape->getFrameRect().pos.x - dx, prevX, delta);
  BOOST_CHECK_CLOSE(shape->getFrameRect().pos.y - dy, prevY, delta);
  prevX = shape->getFrameRect().pos.x;
  prevY = shape->getFrameRect().pos.y;
  pozdnyakov::point_t point{431, -11};
  dx = point.x - shape->getFrameRect().pos.x;
  dy = point.y - shape->getFrameRect().pos.y;
  shape->move(point);
  BOOST_CHECK_CLOSE(shape->getFrameRect().pos.x - dx, prevX, delta);
  BOOST_CHECK_CLOSE(shape->getFrameRect().pos.y - dy, prevY, delta);
}

UniqueShape makeRect()
{
  const double width = 99.3;
  const double height = 7;
  const pozdnyakov::point_t pos{13, 12};
  UniqueShape shape = std::make_unique< pozdnyakov::Rectangle >(width, height, pos);
  return shape;
}

UniqueShape makeCircle()
{
  const double rad = 88;
  const pozdnyakov::point_t pos{77, 13};
  UniqueShape shape = std::make_unique< pozdnyakov::Circle >(rad, pos);
  return shape;
}

UniqueShape makeCompositeShape()
{
  UniqueShapes shapes = std::make_unique< UniqueShape[] >(2);
  shapes[0] = makeCircle();
  shapes[1] = makeRect();
  UniqueShape cshape = std::make_unique< pozdnyakov::CompositeShape >(std::move(shapes), 2);
  return cshape;
}
