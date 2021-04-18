#include "test-functions.hpp"
#include "boost/test/unit_test.hpp"

namespace lab = shkurov;

BOOST_AUTO_TEST_SUITE(composite_shape_test)

BOOST_AUTO_TEST_CASE(move_semantics)
{
  lab::CompositeShape composite(lab::makeCircle(), lab::makeRectangle());
  double originArea = composite.getArea();
  lab::CompositeShape moved_shape(std::move(composite));
  BOOST_CHECK_CLOSE_FRACTION(originArea, moved_shape.getArea(), EPSILON);

  composite = std::move(moved_shape);
  BOOST_CHECK_CLOSE_FRACTION(originArea, composite.getArea(), EPSILON);
}

BOOST_AUTO_TEST_CASE(move_correct_center_translocation)
{
  lab::testMoveToPoint(*(lab::makeCompositeShape()));
}

BOOST_AUTO_TEST_CASE(scale_correct_modification)
{
  lab::testScale(*(lab::makeCompositeShape()));
}

BOOST_AUTO_TEST_CASE(scale_throw_exception)
{
  BOOST_CHECK_THROW(lab::invalidScale(*(lab::makeCompositeShape())), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END();
