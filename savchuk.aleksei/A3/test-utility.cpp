#include "test-utility.hpp"

#include <initializer_list>

#include <boost/test/unit_test.hpp>
#include <boost/test/tools/floating_point_comparison.hpp>

#include "test-values.hpp"
#include "shape-utility.hpp"

namespace lab = savchuk;

const double TOLERANCE = 0.001;

std::unique_ptr< lab::Shape > lab::makeRect()
{
  return std::make_unique< Rectangle >(RECT_POS, WIDTH, HEIGHT);
}

std::unique_ptr< lab::Shape > lab::makeCirc()
{
  return std::make_unique< Circle >(CIRC_POS, RADIUS);
}

std::unique_ptr< lab::Shape > lab::makeComposite()
{
  std::initializer_list< std::unique_ptr< Shape > > il{ makeRect(), makeCirc() };
  return std::make_unique< CompositeShape >(il);
}

void lab::checkMoveInvariant(lab::Shape& s, const lab::point_t& p)
{
  rectangle_t r = s.getFrameRect();
  s.move(p);
  BOOST_CHECK_CLOSE(getWidth(s), r.width, TOLERANCE);
  BOOST_CHECK_CLOSE(getHeight(s), r.height, TOLERANCE);
}

void lab::checkMoveInvariant(lab::Shape& s, double dx, double dy)
{
  rectangle_t r = s.getFrameRect();
  s.move(dx, dy);
  BOOST_CHECK_CLOSE(getWidth(s), r.width, TOLERANCE);
  BOOST_CHECK_CLOSE(getHeight(s), r.height, TOLERANCE);
}

void lab::checkScaleFrameRect(lab::Shape& s, double k)
{
  rectangle_t r = s.getFrameRect();
  s.scale(k);
  BOOST_CHECK_CLOSE(getWidth(s), k * r.width, TOLERANCE);
  BOOST_CHECK_CLOSE(getHeight(s), k * r.height, TOLERANCE);
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
