#include <boost/test/unit_test.hpp>

#include "rectangle.hpp"
#include "circle.hpp"
#include "composite-shape.hpp"
#include "test-utility.hpp"

namespace lab = savchuk;

BOOST_AUTO_TEST_SUITE(composite_shape)

lab::Rectangle rect({ { 2, 3 }, 5, 6 });
lab::Circle circ1({ { 21, 13}, 7 });
lab::Circle circ2({ { 91, 87}, 5 });
lab::CompositeShape comp({ &rect, &circ1, &circ2 });

BOOST_AUTO_TEST_CASE(move_invariant)
{
  lab::CompositeShape s(comp);
  checkMoveInvariant(s, { 11, 13 });
  checkMoveInvariant(s, 11, 13);
}

BOOST_AUTO_TEST_CASE(scale_frame_rectangle)
{
  lab::CompositeShape s(comp);
  checkScaleFrameRect(s, 3);
}

BOOST_AUTO_TEST_CASE(scale_area)
{
  lab::CompositeShape s(comp);
  checkScaleArea(s, 3);
  checkScaleArea(s, 0.3);
}

BOOST_AUTO_TEST_CASE(scale_invalid_argument)
{
  lab::CompositeShape s(comp);
  checkScaleInvalidArgument(s, -3);
}

BOOST_AUTO_TEST_SUITE_END()
