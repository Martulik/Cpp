#include "test-functions.hpp"
#include "circle.hpp"
#include "rectangle.hpp"

namespace poz = pozdnyakov;

void testScale(poz::UniqueShape shape)
{
  double area = shape->getArea();
  double k1 = 0.2;
  shape->safeScale(k1);
  BOOST_CHECK_CLOSE(shape->getArea(), area * k1 * k1, delta);
  area = shape->getArea();
  double k2 = 10;
  shape->safeScale(k2);
  BOOST_CHECK_CLOSE(shape->getArea(), area * k2 * k2, delta);
}

void testMove(poz::UniqueShape shape)
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
  poz::point_t point{431, -11};
  dx = point.x - shape->getFrameRect().pos.x;
  dy = point.y - shape->getFrameRect().pos.y;
  shape->move(point);
  BOOST_CHECK_CLOSE(shape->getFrameRect().pos.x - dx, prevX, delta);
  BOOST_CHECK_CLOSE(shape->getFrameRect().pos.y - dy, prevY, delta);
}

poz::UniqueShape makeRect(double width, double height, poz::point_t pos)
{
  //const double width = 99.3;
  //const double height = 7;
  //const poz::point_t pos{13, 12};
  poz::UniqueShape shape = std::make_unique< poz::Rectangle >(width, height, pos);
  return shape;
}

poz::UniqueShape makeCircle(double rad, poz::point_t pos)
{
  //const double rad = 88;
  //const poz::point_t pos{77, 13};
  poz::UniqueShape shape = std::make_unique< poz::Circle >(rad, pos);
  return shape;
}

poz::UniqueShape makeCompositeShape()
{
  poz::UniqueShapes shapes = std::make_unique< poz::UniqueShape[] >(2);
  shapes[0] = makeCircle(88, poz::point_t{77, 13});
  shapes[1] = makeRect(99.3, 7, poz::point_t{13, 12});
  poz::UniqueShape cshape = std::make_unique< poz::CompositeShape >(std::move(shapes), 2);
  return cshape;
}
