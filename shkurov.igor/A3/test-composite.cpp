#include "test-functions.hpp"
#include "boost/test/unit_test.hpp"

namespace ss = shkurov;

BOOST_AUTO_TEST_SUITE(composite_shape_test)

BOOST_AUTO_TEST_CASE(move_semantics)
{
  ss::CompositeShape composite(ss::makeCircle(), ss::makeRectangle());
  double originArea = composite.getArea();
  ss::CompositeShape moved_shape(std::move(composite));
  BOOST_CHECK_CLOSE_FRACTION(originArea, moved_shape.getArea(), TOLERANCE);

  composite = std::move(moved_shape);
  BOOST_CHECK_CLOSE_FRACTION(originArea, composite.getArea(), TOLERANCE);
}

BOOST_AUTO_TEST_CASE(move_correct_center_translocation)
{
  ss::testMoveToPoint(*(ss::makeCompositeShape()));
}

BOOST_AUTO_TEST_CASE(scale_correct_modification)
{
  ss::testScale(*(ss::makeCompositeShape()));
}

BOOST_AUTO_TEST_CASE(scale_throw_exception)
{
  BOOST_CHECK_THROW(ss::invalidScale(*(ss::makeCompositeShape())), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END();
