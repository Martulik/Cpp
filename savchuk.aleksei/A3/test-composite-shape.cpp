#include <boost/test/unit_test.hpp>

#include "rectangle.hpp"
#include "circle.hpp"
#include "composite-shape.hpp"
#include "test-utility.hpp"

namespace lab = savchuk;

lab::CompositeShape makeComposite(const lab::Rectangle& r, const lab::Circle& c)
{
  return lab::CompositeShape({ &r, &c });
}

BOOST_AUTO_TEST_SUITE(composite_shape)

const lab::point_t& POS_1 = { 2.3, -7.1 };
const double WIDTH = 6.1;
const double HEIGHT = 9.4;
const lab::point_t& POS_2 = { 42.8, -11.7 };
const double RADIUS = 3.5;
const double CORRECT_SCALE_FACTOR = 4.6;
const double WRONG_SCALE_FACTOR = -5.1;

BOOST_AUTO_TEST_CASE(move_invariant)
{
  lab::Rectangle r = makeRect(POS_1, WIDTH, HEIGHT);
  lab::Circle c = makeCirc(POS_1, RADIUS);
  lab::CompositeShape comp = makeComposite(r, c);
  checkMoveInvariant(comp, { -1.6, 13.5 });
  checkMoveInvariant(comp, 2.3, -12.6);
}

BOOST_AUTO_TEST_CASE(scale_frame_rectangle)
{
  lab::Rectangle r = makeRect(POS_1, WIDTH, HEIGHT);
  lab::Circle c = makeCirc(POS_1, RADIUS);
  lab::CompositeShape comp = makeComposite(r, c);
  checkScaleFrameRect(comp, CORRECT_SCALE_FACTOR);
}

BOOST_AUTO_TEST_CASE(scale_area)
{
  lab::Rectangle r = makeRect(POS_1, WIDTH, HEIGHT);
  lab::Circle c = makeCirc(POS_1, RADIUS);
  lab::CompositeShape comp = makeComposite(r, c);
  checkScaleArea(comp, CORRECT_SCALE_FACTOR);
}

BOOST_AUTO_TEST_CASE(scale_invalid_argument)
{
  lab::Rectangle r = makeRect(POS_1, WIDTH, HEIGHT);
  lab::Circle c = makeCirc(POS_1, RADIUS);
  lab::CompositeShape comp = makeComposite(r, c);
  checkScaleInvalidArgument(comp, WRONG_SCALE_FACTOR);
}

BOOST_AUTO_TEST_SUITE_END()
