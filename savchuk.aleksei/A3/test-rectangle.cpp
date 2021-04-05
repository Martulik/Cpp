#include <boost/test/unit_test.hpp>

#include "test-utility.hpp"
#include "test-values.hpp"

namespace lab = savchuk;

BOOST_AUTO_TEST_SUITE(rectangle)

BOOST_AUTO_TEST_CASE(move_invariant)
{
  lab::Rectangle r = lab::makeRect();
  lab::checkMoveInvariant(r, { -1.6, 13.5 });
  lab::checkMoveInvariant(r, 2.3, -12.6);
}

BOOST_AUTO_TEST_CASE(scale_frame_rectangle)
{
  lab::Rectangle r = lab::makeRect();
  lab::checkScaleFrameRect(r, CORRECT_SCALE_FACTOR);
}

BOOST_AUTO_TEST_CASE(scale_area)
{
  lab::Rectangle r = lab::makeRect();
  lab::checkScaleArea(r, CORRECT_SCALE_FACTOR);
}

BOOST_AUTO_TEST_CASE(scale_invalid_argument)
{
  lab::Rectangle r = lab::makeRect();
  lab::checkScaleInvalidArgument(r, WRONG_SCALE_FACTOR);
}

BOOST_AUTO_TEST_SUITE_END();
