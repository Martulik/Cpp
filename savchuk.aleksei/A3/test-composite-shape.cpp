#include <boost/test/unit_test.hpp>

#include "test-utility.hpp"
#include "test-values.hpp"

namespace lab = savchuk;

BOOST_AUTO_TEST_SUITE(composite_shape)

BOOST_AUTO_TEST_CASE(move_invariant)
{
  lab::CompositeShape comp = lab::makeComposite();
  lab::checkMoveInvariant(comp, { -1.6, 13.5 });
  lab::checkMoveInvariant(comp, 2.3, -12.6);
}

BOOST_AUTO_TEST_CASE(scale_frame_rectangle)
{
  lab::CompositeShape comp = lab::makeComposite();
  lab::checkScaleFrameRect(comp, CORRECT_SCALE_FACTOR);
}

BOOST_AUTO_TEST_CASE(scale_area)
{
  lab::CompositeShape comp = lab::makeComposite();
  lab::checkScaleArea(comp, CORRECT_SCALE_FACTOR);
}

BOOST_AUTO_TEST_CASE(scale_invalid_argument)
{
  lab::CompositeShape comp = lab::makeComposite();
  lab::checkScaleInvalidArgument(comp, WRONG_SCALE_FACTOR);
}

BOOST_AUTO_TEST_CASE(correct_frame_rectangle)
{
  const lab::point_t POS = { 0, 0 };
  const double SIDE = 1;
  const double RAD = 100;
  const lab::rectangle_t FRAME_RECT = { POS, 2 * RAD, 2 * RAD };
  lab::Rectangle r(POS, SIDE, SIDE);
  lab::Circle c(POS, RAD);
  lab::CompositeShape comp({ &r, &c });
  lab::checkCorrectFrameRect(comp, FRAME_RECT);
}

BOOST_AUTO_TEST_SUITE_END()
