#include <boost/test/unit_test.hpp>

#include "test-utility.hpp"
#include "test-values.hpp"

namespace lab = savchuk;

BOOST_AUTO_TEST_SUITE(rectangle)

BOOST_AUTO_TEST_CASE(move_invariant)
{
  std::unique_ptr< lab::Shape > r = lab::makeRect();
  lab::checkMoveInvariant(*r, { -1.6, 13.5 });
  lab::checkMoveInvariant(*r, 2.3, -12.6);
}

BOOST_AUTO_TEST_CASE(scale_frame_rectangle)
{
  std::unique_ptr< lab::Shape > r = lab::makeRect();
  lab::checkScaleFrameRect(*r, lab::CORRECT_SCALE_FACTOR);
}

BOOST_AUTO_TEST_CASE(scale_area)
{
  std::unique_ptr< lab::Shape > r = lab::makeRect();
  lab::checkScaleArea(*r, lab::CORRECT_SCALE_FACTOR);
}

BOOST_AUTO_TEST_CASE(scale_invalid_argument)
{
  std::unique_ptr< lab::Shape > r = lab::makeRect();
  lab::checkScaleInvalidArgument(*r, lab::WRONG_SCALE_FACTOR);
}

BOOST_AUTO_TEST_SUITE_END();
