#include <boost/test/included/unit_test.hpp>

#include "rectangle.hpp"
#include "test-utility.hpp"

namespace lab = savchuk;

BOOST_AUTO_TEST_SUITE(rectangle)

lab::Rectangle rect({ { 2, 3 }, 5, 6 });

BOOST_AUTO_TEST_CASE(move_invariant)
{
  lab::Rectangle r(rect);
  checkMoveInvariant(r, { 11, 13 });
  checkMoveInvariant(r, 11, 13);
}

BOOST_AUTO_TEST_CASE(scale_frame_rectangle)
{
  lab::Rectangle r(rect);
  checkScaleFrameRect(r, 3);
}

BOOST_AUTO_TEST_CASE(scale_area)
{
  lab::Rectangle r(rect);
  checkScaleArea(r, 3);
  checkScaleArea(r, 0.3);
}

BOOST_AUTO_TEST_CASE(scale_invalid_argument)
{
  lab::Rectangle r(rect);
  checkScaleInvalidArgument(r, -3);
}

BOOST_AUTO_TEST_SUITE_END();
