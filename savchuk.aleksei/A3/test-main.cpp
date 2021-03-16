#define BOOST_TEST_MODULE test

#include <boost/test/included/unit_test.hpp>
#include <boost/test/tools/floating_point_comparison.hpp>

#include "rectangle.hpp"
#include "circle.hpp"
#include "composite-shape.hpp"

namespace lab = savchuk;

const double tolerance = std::numeric_limits< double >::epsilon();

void checkMoveInvariant(lab::Shape& s, const lab::point_t& p)
{
  lab::rectangle_t r1 = s.getFrameRect();
  s.move(p);
  lab::rectangle_t r2 = s.getFrameRect();
  BOOST_CHECK_EQUAL(r2.width, r1.width);
  BOOST_CHECK_EQUAL(r2.height, r1.height);
}

void checkMoveInvariant(lab::Shape& s, double dx, double dy)
{
  lab::rectangle_t r1 = s.getFrameRect();
  s.move(dx, dy);
  lab::rectangle_t r2 = s.getFrameRect();
  BOOST_CHECK_EQUAL(r2.width, r1.width);
  BOOST_CHECK_EQUAL(r2.height, r1.height);
}

void checkScaleFrameRect(lab::Shape& s, double k)
{
  lab::rectangle_t r1 = s.getFrameRect();
  s.scale(k);
  lab::rectangle_t r2 = s.getFrameRect();
  BOOST_CHECK_EQUAL(r2.width, k * r1.width);
  BOOST_CHECK_EQUAL(r2.height, k * r1.height);
}

void checkScaleArea(lab::Shape& s, double k)
{
  double a1 = s.getArea();
  s.scale(k);
  double a2 = s.getArea();
  BOOST_CHECK_CLOSE_FRACTION(a2, k * k * a1, tolerance);
}

void checkScaleInvalidArgument(lab::Shape& s, double k)
{
  BOOST_CHECK_THROW(s.scale(k), std::invalid_argument);
}

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
