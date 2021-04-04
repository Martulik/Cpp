#include "test-utility.hpp"

#include <boost/test/unit_test.hpp>
#include <boost/test/tools/floating_point_comparison.hpp>

#include "rectangle.hpp"
#include "circle.hpp"
#include "composite-shape.hpp"
#include "shape-utility.hpp"

namespace lab = savchuk;

const double TOLERANCE = 0.001;

lab::Rectangle makeRect(const lab::point_t& p, double w, double h)
{
  return lab::Rectangle(p, w, h);
}

lab::Circle makeCirc(const lab::point_t& p, double r)
{
  return lab::Circle(p, r);
}

void checkMoveInvariant(lab::Shape& s, const lab::point_t& p)
{
  lab::rectangle_t r1 = s.getFrameRect();
  s.move(p);
  lab::rectangle_t r2 = s.getFrameRect();
  BOOST_CHECK_CLOSE(r2.width, r1.width, TOLERANCE);
  BOOST_CHECK_CLOSE(r2.height, r1.height, TOLERANCE);
}

void checkMoveInvariant(lab::Shape& s, double dx, double dy)
{
  lab::rectangle_t r1 = s.getFrameRect();
  s.move(dx, dy);
  lab::rectangle_t r2 = s.getFrameRect();
  BOOST_CHECK_CLOSE(r2.width, r1.width, TOLERANCE);
  BOOST_CHECK_CLOSE(r2.height, r1.height, TOLERANCE);
}

void checkScaleFrameRect(lab::Shape& s, double k)
{
  lab::rectangle_t r1 = s.getFrameRect();
  s.scale(k);
  lab::rectangle_t r2 = s.getFrameRect();
  BOOST_CHECK_CLOSE(r2.width, k * r1.width, TOLERANCE);
  BOOST_CHECK_CLOSE(r2.height, k * r1.height, TOLERANCE);
}

void checkScaleArea(lab::Shape& s, double k)
{
  double a1 = s.getArea();
  s.scale(k);
  double a2 = s.getArea();
  BOOST_CHECK_CLOSE(a2, k * k * a1, TOLERANCE);
}

void checkScaleInvalidArgument(lab::Shape& s, double k)
{
  BOOST_CHECK_THROW(s.scale(k), std::invalid_argument);
}

void checkCorrectFrameRect(const lab::Shape& s, const lab::rectangle_t& r)
{
  BOOST_CHECK_CLOSE(lab::getWidth(s), r.width, TOLERANCE);
  BOOST_CHECK_CLOSE(lab::getHeight(s), r.height, TOLERANCE);
  BOOST_CHECK_CLOSE(lab::getPosX(s), r.pos.x, TOLERANCE);
  BOOST_CHECK_CLOSE(lab::getPosY(s), r.pos.y, TOLERANCE);
}
