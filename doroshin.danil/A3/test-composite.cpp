#include <boost/test/unit_test.hpp>
#include "test-utility.hpp"
#include "circle.hpp"
#include "rectangle.hpp"
#include "composite-shape.hpp"

namespace dan = doroshin;
using namespace dan::literals;

class CompositeTestFixture
{
public:
  CompositeTestFixture():
    shape(dan::Rectangle{2_ud, 3_ud, p1}, dan::Circle{p2, 2_ud})
  {}

  dan::CompositeShape shape;
private:
  static const dan::point_t p1;
  static const dan::point_t p2;
};

const dan::point_t CompositeTestFixture::p1{-1, 0};
const dan::point_t CompositeTestFixture::p2{1, 1};

BOOST_FIXTURE_TEST_SUITE(Composite, CompositeTestFixture)

BOOST_AUTO_TEST_CASE(test_move)
{
  dan::testMoveRel(shape, {1, 2});
  dan::testMoveRel(shape, {-5, 7});
  dan::testMoveAbs(shape, {65, -33});
}

BOOST_AUTO_TEST_CASE(test_scale)
{
  dan::testScale(shape, 4.5_ud);
  dan::testScale(shape, 0.1_ud);
}

BOOST_AUTO_TEST_CASE(copy)
{
  dan::CompositeShape cpy(shape);

  BOOST_CHECK_EQUAL(shape.getArea(), cpy.getArea());
  equalSize(shape.getFrameRect(), cpy.getFrameRect());
  BOOST_CHECK_EQUAL(dan::getX(shape), dan::getX(cpy));
  BOOST_CHECK_EQUAL(dan::getY(shape), dan::getY(cpy));
}

BOOST_AUTO_TEST_SUITE_END()
