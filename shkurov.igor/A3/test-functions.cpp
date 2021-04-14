#include "test-functions.hpp"

#include <limits>
#include "boost/test/unit_test.hpp"

namespace ss = shkurov;

using std::make_unique;

struct point_t;

const ss::point_t CIRCLE_POS = {3, -5};
const ss::point_t RECTANGLE_POS = {-8, 1};
const ss::point_t FINAL_POS = {0, 4};
const double A = 7.0;
const double B = 10.0;
const double C = 4.0;
const double K = 3.0;

shapePtr ss::makeBadCircle()
{
  return make_unique< ss::Circle >(ss::Circle(CIRCLE_POS, -A));
}

shapePtr ss::makeBadRectangle()
{
  return make_unique< ss::Rectangle >(ss::Rectangle(RECTANGLE_POS, B, -C));
}

shapePtr ss::makeCircle()
{
  return make_unique< ss::Circle >(ss::Circle(CIRCLE_POS, A));
}

shapePtr ss::makeRectangle()
{
  return make_unique< ss::Rectangle >(ss::Rectangle(RECTANGLE_POS, B, C));
}

shapePtr ss::makeCompositeShape()
{
  shapePtr circle(make_unique< ss::Circle >(ss::Circle(CIRCLE_POS, A)));
  shapePtr rectangle(make_unique< ss::Rectangle >(ss::Rectangle(RECTANGLE_POS, B, C)));

  return shapePtr(std::make_unique< ss::CompositeShape>
    (ss::CompositeShape(std::move(circle), std::move(rectangle))));
}

void ss::testMoveToPoint(ss::Shape& shape)
{
  double originHeight = ss::getHeight(shape);
  double originWidth = ss::getWidth(shape);
  double originArea = shape.getArea();

  shape.move(FINAL_POS);

  BOOST_CHECK_CLOSE_FRACTION(originHeight, ss::getHeight(shape), TOLERANCE);
  BOOST_CHECK_CLOSE_FRACTION(originWidth, ss::getWidth(shape), TOLERANCE);
  BOOST_CHECK_CLOSE_FRACTION(originArea, shape.getArea(), TOLERANCE);
}

void ss::testScale(ss::Shape& shape)
{
  double predArea = shape.getArea() * K * K;

  shape.scale(K);

  BOOST_CHECK_CLOSE_FRACTION(predArea, shape.getArea(), TOLERANCE);
}

void ss::invalidScale(ss::Shape& shape)
{
  shape.scale(-K);
}
