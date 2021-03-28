#include <boost/test/included/unit_test.hpp>

#include "circle.hpp"
#include "test-utility.hpp"

namespace lab = savchuk;

BOOST_AUTO_TEST_SUITE(circle)

lab::Circle circ({ { 2, 3 }, 5 });

BOOST_AUTO_TEST_CASE(move_invariant)
{
  lab::Circle c(circ);
  checkMoveInvariant(c, { 11, 13 });
  checkMoveInvariant(c, 11, 13);
}

BOOST_AUTO_TEST_CASE(scale_frame_rectangle)
{
  lab::Circle c(circ);
  checkScaleFrameRect(c, 3);
}

BOOST_AUTO_TEST_CASE(scale_area)
{
  lab::Circle c(circ);
  checkScaleArea(c, 3);
  checkScaleArea(c, 0.3);
}

BOOST_AUTO_TEST_CASE(scale_invalid_argument)
{
  lab::Circle c(circ);
  checkScaleInvalidArgument(c, -3);
}

BOOST_AUTO_TEST_SUITE_END()
