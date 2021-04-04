#include <boost/test/unit_test.hpp>

#include "rectangle.hpp"
#include "circle.hpp"
#include "composite-shape.hpp"
#include "test-utility.hpp"
#include "test-values.hpp"

namespace lab = savchuk;

lab::CompositeShape makeComposite()
{
  lab::Rectangle r = makeRect(RECT_POS, WIDTH, HEIGHT);
  lab::Circle c = makeCirc(CIRC_POS, RADIUS);
  return lab::CompositeShape({ &r, &c });
}

BOOST_AUTO_TEST_SUITE(composite_shape)

BOOST_AUTO_TEST_CASE(move_invariant)
{
  lab::CompositeShape comp = makeComposite();
  checkMoveInvariant(comp, { -1.6, 13.5 });
  checkMoveInvariant(comp, 2.3, -12.6);
}

BOOST_AUTO_TEST_CASE(scale_frame_rectangle)
{
  lab::CompositeShape comp = makeComposite();
  checkScaleFrameRect(comp, CORRECT_SCALE_FACTOR);
}

BOOST_AUTO_TEST_CASE(scale_area)
{
  lab::CompositeShape comp = makeComposite();
  checkScaleArea(comp, CORRECT_SCALE_FACTOR);
}

BOOST_AUTO_TEST_CASE(scale_invalid_argument)
{
  lab::CompositeShape comp = makeComposite();
  checkScaleInvalidArgument(comp, WRONG_SCALE_FACTOR);
}

BOOST_AUTO_TEST_CASE(correct_frame_rectangle)
{
  const lab::point_t POS = { 0, 0 };
  const double SIDE = 1;
  const double RAD = 100;
  const lab::rectangle_t FRAME_RECT = { POS, 2 * RAD, 2 * RAD };
  lab::Rectangle r = makeRect(POS, SIDE, SIDE);
  lab::Circle c = makeCirc(POS, RAD);
  lab::CompositeShape comp({ &r, &c });
  checkCorrectFrameRect(comp, FRAME_RECT);
}

BOOST_AUTO_TEST_SUITE_END()
