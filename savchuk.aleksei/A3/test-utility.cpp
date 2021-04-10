#include "test-utility.hpp"

#include <initializer_list>
#include <memory>

#include <boost/test/unit_test.hpp>
#include <boost/test/tools/floating_point_comparison.hpp>

#include "test-values.hpp"
#include "shape-utility.hpp"

namespace lab = savchuk;

const double TOLERANCE = 0.001;

lab::Rectangle lab::makeRect()
{
  return Rectangle(RECT_POS, WIDTH, HEIGHT);
}

lab::Circle lab::makeCirc()
{
  return Circle(CIRC_POS, RADIUS);
}

lab::CompositeShape lab::makeComposite()
{
  std::unique_ptr< lab::Shape > r = std::make_unique< lab::Rectangle >(makeRect());
  std::unique_ptr< lab::Shape > c = std::make_unique< lab::Circle >(makeCirc());
  std::initializer_list< std::unique_ptr< lab::Shape > > il{std::move(r), std::move(c)};
  return CompositeShape(il);
}

void lab::checkMoveInvariant(lab::Shape& s, const lab::point_t& p)
{
  rectangle_t r1 = s.getFrameRect();
  s.move(p);
  rectangle_t r2 = s.getFrameRect();
  BOOST_CHECK_CLOSE(r2.width, r1.width, TOLERANCE);
  BOOST_CHECK_CLOSE(r2.height, r1.height, TOLERANCE);
}

void lab::checkMoveInvariant(lab::Shape& s, double dx, double dy)
{
  rectangle_t r1 = s.getFrameRect();
  s.move(dx, dy);
  rectangle_t r2 = s.getFrameRect();
  BOOST_CHECK_CLOSE(r2.width, r1.width, TOLERANCE);
  BOOST_CHECK_CLOSE(r2.height, r1.height, TOLERANCE);
}

void lab::checkScaleFrameRect(lab::Shape& s, double k)
{
  rectangle_t r1 = s.getFrameRect();
  s.scale(k);
  rectangle_t r2 = s.getFrameRect();
  BOOST_CHECK_CLOSE(r2.width, k * r1.width, TOLERANCE);
  BOOST_CHECK_CLOSE(r2.height, k * r1.height, TOLERANCE);
}

void lab::checkScaleArea(lab::Shape& s, double k)
{
  double a1 = s.getArea();
  s.scale(k);
  double a2 = s.getArea();
  BOOST_CHECK_CLOSE(a2, k * k * a1, TOLERANCE);
}

void lab::checkScaleInvalidArgument(lab::Shape& s, double k)
{
  BOOST_CHECK_THROW(s.scale(k), std::invalid_argument);
}

void lab::checkCorrectFrameRect(const lab::Shape& s, const lab::rectangle_t& r)
{
  BOOST_CHECK_CLOSE(getWidth(s), r.width, TOLERANCE);
  BOOST_CHECK_CLOSE(getHeight(s), r.height, TOLERANCE);
  BOOST_CHECK_CLOSE(getPosX(s), r.pos.x, TOLERANCE);
  BOOST_CHECK_CLOSE(getPosY(s), r.pos.y, TOLERANCE);
}
