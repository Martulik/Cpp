#include <boost/test/unit_test.hpp>

#include "circle.hpp"
#include "test-utility.hpp"
#include "test-values.hpp"

namespace lab = savchuk;

BOOST_AUTO_TEST_SUITE(circle)

BOOST_AUTO_TEST_CASE(move_invariant)
{
  lab::Circle c = makeCirc(CIRC_POS, RADIUS);
  checkMoveInvariant(c, { -1.6, 13.5 });
  checkMoveInvariant(c, 2.3, -12.6);
}

BOOST_AUTO_TEST_CASE(scale_frame_rectangle)
{
  lab::Circle c = makeCirc(CIRC_POS, RADIUS);
  checkScaleFrameRect(c, CORRECT_SCALE_FACTOR);
}

BOOST_AUTO_TEST_CASE(scale_area)
{
  lab::Circle c = makeCirc(CIRC_POS, RADIUS);
  checkScaleArea(c, CORRECT_SCALE_FACTOR);
}

BOOST_AUTO_TEST_CASE(scale_invalid_argument)
{
  lab::Circle c = makeCirc(CIRC_POS, RADIUS);
  checkScaleInvalidArgument(c, WRONG_SCALE_FACTOR);
}

BOOST_AUTO_TEST_SUITE_END()
