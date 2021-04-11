#include "test-functions.hpp"

#include <boost/test/unit_test.hpp>
#include <boost/test/tools/floating_point_comparison.hpp>
#include <initializer_list>
#include <memory>

namespace fer = ferapontov;
using UniqueShp = std::unique_ptr< fer::Shape >;

const double e = 0.001;

fer::Rectangle fer::makeRectangle()
{
  return Rectangle(5, 5, {0, 0});
}

fer::Circle fer::makeCircle()
{
  return Circle(5, {0, 0});
}

fer::CompositeShape fer::makeComposite()
{
  UniqueShp circ = std::make_unique< fer::Circle >(makeCircle());
  UniqueShp rec = std::make_unique< fer::Rectangle >(makeRectangle());
  std::initializer_list< UniqueShp > c{std::move(circ), std::move(rec)};
  return CompositeShape(c);
}

void fer::test_move(fer::Shape& shp, const fer::point_t& pos)
{
  rectangle_t r1 = shp.getFrameRect();
  shp.move(pos);
  rectangle_t r2 = shp.getFrameRect();
  BOOST_CHECK_CLOSE(r1.width, r2.width, e);
  BOOST_CHECK_CLOSE(r1.height, r2.height, e);
}

void fer::test_move(fer::Shape& shp, const double dx, const double dy)
{
  rectangle_t r1 = shp.getFrameRect();
  shp.move(dx, dy);
  rectangle_t r2 = shp.getFrameRect();
  BOOST_CHECK_CLOSE(r1.width, r2.width, e);
  BOOST_CHECK_CLOSE(r1.height, r2.height, e);
}

void fer::test_scale(fer::Shape& shp, const double k)
{
  rectangle_t r1 = shp.getFrameRect();
  shp.scale(k);
  rectangle_t r2 = shp.getFrameRect();
  BOOST_CHECK_CLOSE(k * r1.width, r2.width, e);
  BOOST_CHECK_CLOSE(k * r1.height, r2.height, e);
}

void fer::test_invalid_argument(fer::Shape& shp, const double k)
{
  BOOST_CHECK_THROW(shp.scale(k), std::invalid_argument);
}
