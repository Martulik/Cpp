#include <boost/test/unit_test.hpp>

#include "rectangle.hpp"
#include "test-utility.hpp"
#include "test-values.hpp"

namespace lab = savchuk;

BOOST_AUTO_TEST_SUITE(rectangle)

BOOST_AUTO_TEST_CASE(move_invariant)
{
  lab::Rectangle r = makeRect(RECT_POS, WIDTH, HEIGHT);
  checkMoveInvariant(r, { -1.6, 13.5 });
  checkMoveInvariant(r, 2.3, -12.6);
}

BOOST_AUTO_TEST_CASE(scale_frame_rectangle)
{
  lab::Rectangle r = makeRect(RECT_POS, WIDTH, HEIGHT);
  checkScaleFrameRect(r, CORRECT_SCALE_FACTOR);
}

BOOST_AUTO_TEST_CASE(scale_area)
{
  lab::Rectangle r = makeRect(RECT_POS, WIDTH, HEIGHT);
  checkScaleArea(r, CORRECT_SCALE_FACTOR);
}

BOOST_AUTO_TEST_CASE(scale_invalid_argument)
{
  lab::Rectangle r = makeRect(RECT_POS, WIDTH, HEIGHT);
  checkScaleInvalidArgument(r, WRONG_SCALE_FACTOR);
}

BOOST_AUTO_TEST_SUITE_END();
