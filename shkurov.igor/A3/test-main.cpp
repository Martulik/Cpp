#define BOOST_TEST_MODULE A3
#include "test-functions.hpp"

#include <limits>
#include <stdexcept>
#include <boost/test/included/unit_test.hpp>

const double EPSILON = std::numeric_limits< double >::epsilon();

BOOST_AUTO_TEST_SUITE(rectangle_test)

std::unique_ptr< shkurov::Shape > rect_ptr = makeRectangle();

BOOST_AUTO_TEST_CASE(constructor_throw_exception)
{
  BOOST_CHECK_THROW(makeBadCircle(), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(move)
{
  testMoveToPoint(rect_ptr.get());
}

BOOST_AUTO_TEST_CASE(scale)
{
  testScale(rect_ptr.get());
}

BOOST_AUTO_TEST_CASE(scale_throw_exception)
{
  BOOST_CHECK_THROW(invalidScale(rect_ptr.get()), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END();


BOOST_AUTO_TEST_SUITE(circle_test)

std::unique_ptr< shkurov::Shape > circle_ptr = makeCircle();

BOOST_AUTO_TEST_CASE(constructor_throw_exception)
{
  BOOST_CHECK_THROW(makeBadCircle(), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(move)
{
  testMoveToPoint(circle_ptr.get());
}

BOOST_AUTO_TEST_CASE(scale_correct_modification)
{
  testScale(circle_ptr.get());
}

BOOST_AUTO_TEST_CASE(scale_throw_exception)
{
  BOOST_CHECK_THROW(invalidScale(circle_ptr.get()), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END();


BOOST_AUTO_TEST_SUITE(composite_shape_test)

std::unique_ptr< shkurov::Shape > composite_ptr(new shkurov::CompositeShape({makeCircle(), makeRectangle()}));

BOOST_AUTO_TEST_CASE(move_semantics)
{
  shkurov::CompositeShape composite({makeCircle(), makeRectangle()});
  double origin_area = composite.getArea();
  shkurov::CompositeShape moved_shape(std::move(composite));
  BOOST_CHECK_CLOSE(origin_area, moved_shape.getArea(), EPSILON);

  composite = std::move(moved_shape);
  BOOST_CHECK_CLOSE(origin_area, composite.getArea(), EPSILON);
}

BOOST_AUTO_TEST_CASE(move_correct_center_translocation)
{
  testMoveToPoint(composite_ptr.get());
}

BOOST_AUTO_TEST_CASE(scale_correct_modification)
{
  testScale(composite_ptr.get());
}

BOOST_AUTO_TEST_CASE(scale_throw_exception)
{
  BOOST_CHECK_THROW(invalidScale(composite_ptr.get()), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END();
