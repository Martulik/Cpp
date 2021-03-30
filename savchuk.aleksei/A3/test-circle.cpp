#include <boost/test/unit_test.hpp>

#include "circle.hpp"
#include "test-utility.hpp"

namespace lab = savchuk;

BOOST_AUTO_TEST_SUITE(circle)

const lab::point_t POS = { 2.3, -7.1 };
const double RADIUS = 3.5;
const double CORRECT_SCALE_FACTOR = 4.6;
const double WRONG_SCALE_FACTOR = -5.1;

BOOST_AUTO_TEST_CASE(move_invariant)
{
  lab::Circle c = makeCirc(POS, RADIUS);
  checkMoveInvariant(c, { -1.6, 13.5 });
  checkMoveInvariant(c, 2.3, -12.6);
}

BOOST_AUTO_TEST_CASE(scale_frame_rectangle)
{
  lab::Circle c = makeCirc(POS, RADIUS);
  checkScaleFrameRect(c, CORRECT_SCALE_FACTOR);
}

BOOST_AUTO_TEST_CASE(scale_area)
{
  lab::Circle c = makeCirc(POS, RADIUS);
  checkScaleArea(c, CORRECT_SCALE_FACTOR);
}

BOOST_AUTO_TEST_CASE(scale_invalid_argument)
{
  lab::Circle c = makeCirc(POS, RADIUS);
  checkScaleInvalidArgument(c, WRONG_SCALE_FACTOR);
}

BOOST_AUTO_TEST_SUITE_END()
