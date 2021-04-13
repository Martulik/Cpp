#include "test-functions.hpp"
#include "boost/test/unit_test.hpp"

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
