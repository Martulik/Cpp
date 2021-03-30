#include <boost/test/unit_test.hpp>

#include "rectangle.hpp"
#include "test-utility.hpp"

namespace lab = savchuk;

BOOST_AUTO_TEST_SUITE(rectangle)

const lab::point_t POS = { 2.3, -7.1 };
const double WIDTH = 6.1;
const double HEIGHT = 9.4;
const double CORRECT_SCALE_FACTOR = 4.6;
const double WRONG_SCALE_FACTOR = -5.1;

BOOST_AUTO_TEST_CASE(move_invariant)
{
  lab::Rectangle r = makeRect(POS, WIDTH, HEIGHT);
  checkMoveInvariant(r, { -1.6, 13.5 });
  checkMoveInvariant(r, 2.3, -12.6);
}

BOOST_AUTO_TEST_CASE(scale_frame_rectangle)
{
  lab::Rectangle r = makeRect(POS, WIDTH, HEIGHT);
  checkScaleFrameRect(r, CORRECT_SCALE_FACTOR);
}

BOOST_AUTO_TEST_CASE(scale_area)
{
  lab::Rectangle r = makeRect(POS, WIDTH, HEIGHT);
  checkScaleArea(r, CORRECT_SCALE_FACTOR);
}

BOOST_AUTO_TEST_CASE(scale_invalid_argument)
{
  lab::Rectangle r = makeRect(POS, WIDTH, HEIGHT);
  checkScaleInvalidArgument(r, WRONG_SCALE_FACTOR);
}

BOOST_AUTO_TEST_SUITE_END();
