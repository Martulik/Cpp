#include "test-functions.hpp"

#include <limits>
#include <boost/test/unit_test.hpp>

struct point_t;

const shkurov::point_t CIRCLE_POS = {3, -5};
const shkurov::point_t RECTANGLE_POS = {-8, 1};
const shkurov::point_t FINAL_POS = {0, 4};
const double A = 7.0;
const double B = 10.0;
const double C = 4.0;
const double K = 3.0;
const double TOLERANCE = std::numeric_limits< double >::epsilon();

std::unique_ptr< shkurov::Shape > shkurov::makeBadCircle()
{
   return std::make_unique< shkurov::Circle >(shkurov::Circle(CIRCLE_POS, -A));
}

std::unique_ptr< shkurov::Shape > shkurov::makeBadRectangle()
{
  return std::make_unique< shkurov::Rectangle >(shkurov::Rectangle(RECTANGLE_POS, B, -C));
}

std::unique_ptr< shkurov::Shape > shkurov::makeCircle()
{
  return std::make_unique< shkurov::Circle >(shkurov::Circle(CIRCLE_POS, A));
}

std::unique_ptr< shkurov::Shape > shkurov::makeRectangle()
{
  return std::make_unique< shkurov::Rectangle >(shkurov::Rectangle(RECTANGLE_POS, B, C));
}

std::unique_ptr< shkurov::Shape > shkurov::makeCompositeShape()
{
  std::unique_ptr< shkurov::Shape > circle(std::make_unique< shkurov::Circle >
    (shkurov::Circle(CIRCLE_POS, A)));
  std::unique_ptr< shkurov::Shape > rectangle(std::make_unique< shkurov::Rectangle >
    (shkurov::Rectangle(RECTANGLE_POS, B, C)));

  return std::unique_ptr< shkurov::Shape >(std::make_unique< shkurov::CompositeShape>
    (shkurov::CompositeShape(std::move(circle), std::move(rectangle))));
}

void shkurov::testMoveToPoint(shkurov::Shape& shape)
{
  double origin_height = shape.getHeight();
  double origin_width = shape.getWidth();
  double origin_area = shape.getArea();

  shape.move(FINAL_POS);

  BOOST_CHECK_CLOSE_FRACTION(origin_height, shape.getHeight(), TOLERANCE);
  BOOST_CHECK_CLOSE_FRACTION(origin_width, shape.getWidth(), TOLERANCE);
  BOOST_CHECK_CLOSE_FRACTION(origin_area, shape.getArea(), TOLERANCE);
}

void shkurov::testScale(shkurov::Shape& shape)
{
  double pred_area = shape.getArea() * K * K;

  shape.scale(K);

  BOOST_CHECK_CLOSE_FRACTION(pred_area, shape.getArea(), TOLERANCE);
}

void shkurov::invalidScale(shkurov::Shape& shape)
{
  shape.scale(-K);
}
