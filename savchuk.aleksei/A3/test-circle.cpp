#include <boost/test/unit_test.hpp>

#include "test-utility.hpp"
#include "test-values.hpp"

namespace lab = savchuk;

BOOST_AUTO_TEST_SUITE(circle)

BOOST_AUTO_TEST_CASE(move_invariant)
{
  lab::Circle c = lab::makeCirc();
  lab::checkMoveInvariant(c, { -1.6, 13.5 });
  lab::checkMoveInvariant(c, 2.3, -12.6);
}

BOOST_AUTO_TEST_CASE(scale_frame_rectangle)
{
  lab::Circle c = lab::makeCirc();
  lab::checkScaleFrameRect(c, CORRECT_SCALE_FACTOR);
}

BOOST_AUTO_TEST_CASE(scale_area)
{
  lab::Circle c = lab::makeCirc();
  lab::checkScaleArea(c, CORRECT_SCALE_FACTOR);
}

BOOST_AUTO_TEST_CASE(scale_invalid_argument)
{
  lab::Circle c = lab::makeCirc();
  lab::checkScaleInvalidArgument(c, WRONG_SCALE_FACTOR);
}

BOOST_AUTO_TEST_SUITE_END()
