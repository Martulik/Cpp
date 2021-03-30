#include "test-utility.hpp"

#include <limits>

#include <boost/test/unit_test.hpp>
#include <boost/test/tools/floating_point_comparison.hpp>

#include "rectangle.hpp"
#include "circle.hpp"
#include "composite-shape.hpp"

namespace lab = savchuk;

const double TOLERANCE = std::numeric_limits< double >::epsilon();

lab::Rectangle makeRect(const point_t& p, double w, double h)
{
  return { p, w, h };
}

lab::Circle makeCirc(const point_t& p, double r)
{
  return { p, r };
}

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
  BOOST_CHECK_CLOSE_FRACTION(a2, k * k * a1, TOLERANCE);
}

void checkScaleInvalidArgument(lab::Shape& s, double k)
{
  BOOST_CHECK_THROW(s.scale(k), std::invalid_argument);
}
