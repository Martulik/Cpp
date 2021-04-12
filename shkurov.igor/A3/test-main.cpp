#define BOOST_TEST_MODULE A3
#include "test-functions.hpp"

#include <limits>
#include <stdexcept>
#include <boost/test/included/unit_test.hpp>

const double TOLERANCE = std::numeric_limits< double >::epsilon();

BOOST_AUTO_TEST_SUITE(rectangle_test)

std::unique_ptr< shkurov::Shape > rect_ptr = shkurov::makeRectangle();

BOOST_AUTO_TEST_CASE(constructor_throw_exception)
{
  BOOST_CHECK_THROW(shkurov::makeBadCircle(), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(move)
{
  shkurov::testMoveToPoint(*rect_ptr);
}

BOOST_AUTO_TEST_CASE(scale)
{
  shkurov::testScale(*rect_ptr);
}

BOOST_AUTO_TEST_CASE(scale_throw_exception)
{
  BOOST_CHECK_THROW(shkurov::invalidScale(*rect_ptr), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END();


BOOST_AUTO_TEST_SUITE(circle_test)

std::unique_ptr< shkurov::Shape > circle_ptr = shkurov::makeCircle();

BOOST_AUTO_TEST_CASE(constructor_throw_exception)
{
  BOOST_CHECK_THROW(shkurov::makeBadCircle(), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(move)
{
  shkurov::testMoveToPoint(*circle_ptr);
}

BOOST_AUTO_TEST_CASE(scale_correct_modification)
{
  shkurov::testScale(*circle_ptr);
}

BOOST_AUTO_TEST_CASE(scale_throw_exception)
{
  BOOST_CHECK_THROW(shkurov::invalidScale(*circle_ptr), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END();


BOOST_AUTO_TEST_SUITE(composite_shape_test)

std::unique_ptr< shkurov::Shape > composite_ptr
  (std::make_unique< shkurov::CompositeShape >
    (shkurov::makeCircle(), shkurov::makeRectangle()));

BOOST_AUTO_TEST_CASE(move_semantics)
{
  shkurov::CompositeShape composite(shkurov::makeCircle(), shkurov::makeRectangle());
  double origin_area = composite.getArea();
  shkurov::CompositeShape moved_shape(std::move(composite));
  BOOST_CHECK_CLOSE_FRACTION(origin_area, moved_shape.getArea(), TOLERANCE);

  composite = std::move(moved_shape);
  BOOST_CHECK_CLOSE_FRACTION(origin_area, composite.getArea(), TOLERANCE);
}

BOOST_AUTO_TEST_CASE(move_correct_center_translocation)
{
  shkurov::testMoveToPoint(*composite_ptr);
}

BOOST_AUTO_TEST_CASE(scale_correct_modification)
{
  shkurov::testScale(*composite_ptr);
}

BOOST_AUTO_TEST_CASE(scale_throw_exception)
{
  BOOST_CHECK_THROW(shkurov::invalidScale(*composite_ptr), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END();
