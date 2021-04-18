#include "test-functions.hpp"

#include <limits>
#include "boost/test/unit_test.hpp"

namespace lab = shkurov;

using shapePtr = std::unique_ptr< lab::Shape >;
using CShape = lab::CompositeShape;

struct point_t;

const lab::point_t CIRCLE_POS = {3, -5};
const lab::point_t RECTANGLE_POS = {-8, 1};
const lab::point_t FINAL_POS = {0, 4};
const double A = 7.0;
const double B = 10.0;
const double C = 4.0;
const double K = 3.0;

shapePtr lab::makeBadCircle()
{
  return std::make_unique< Circle >(Circle(CIRCLE_POS, -A));
}

shapePtr lab::makeBadRectangle()
{
  return std::make_unique< Rectangle >(Rectangle(RECTANGLE_POS, B, -C));
}

shapePtr lab::makeCircle()
{
  return std::make_unique< Circle >(Circle(CIRCLE_POS, A));
}

shapePtr lab::makeRectangle()
{
  return std::make_unique< Rectangle >(Rectangle(RECTANGLE_POS, B, C));
}

shapePtr lab::makeCompositeShape()
{
  shapePtr circle(std::make_unique< Circle >(Circle(CIRCLE_POS, A)));
  shapePtr rect(std::make_unique< Rectangle >(Rectangle(RECTANGLE_POS, B, C)));

  return shapePtr(std::make_unique< CShape >(CShape(std::move(circle), std::move(rect))));
}

void lab::testMoveToPoint(lab::Shape& shape)
{
  double originHeight = lab::getHeight(shape);
  double originWidth = lab::getWidth(shape);
  double originArea = shape.getArea();

  shape.move(FINAL_POS);

  BOOST_CHECK_CLOSE_FRACTION(originHeight, lab::getHeight(shape), EPSILON);
  BOOST_CHECK_CLOSE_FRACTION(originWidth, lab::getWidth(shape), EPSILON);
  BOOST_CHECK_CLOSE_FRACTION(originArea, shape.getArea(), EPSILON);
}

void lab::testScale(lab::Shape& shape)
{
  double predArea = shape.getArea() * K * K;

  shape.scale(K);

  BOOST_CHECK_CLOSE_FRACTION(predArea, shape.getArea(), EPSILON);
}

void lab::invalidScale(lab::Shape& shape)
{
  shape.scale(-K);
}
