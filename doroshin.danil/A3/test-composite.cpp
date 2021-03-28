#include <boost/test/unit_test.hpp>
#include "test-utility.hpp"
#include "circle.hpp"
#include "rectangle.hpp"
#include "composite-shape.hpp"

namespace dan = doroshin;
using namespace dan::literals;

class CompositeTestFixture
{
  const dan::point_t p1{-1, 0};
  const dan::point_t p2{1, 1};
public:
  CompositeTestFixture():
    shape(dan::Rectangle{2_ud, 3_ud, p1}, dan::Circle{p2, 2_ud})
  {
    BOOST_TEST_MESSAGE("Composite ctr");
  }

  dan::CompositeShape shape;
};

BOOST_FIXTURE_TEST_SUITE(Composite, CompositeTestFixture)

BOOST_AUTO_TEST_CASE(test_move)
{
  dan::test_move_rel(shape, {1, 2});
  dan::test_move_rel(shape, {-5, 7});
  dan::test_move_abs(shape, {65, -33});
}

BOOST_AUTO_TEST_CASE(test_scale)
{
  dan::test_scale(shape, 4.5_ud);
  dan::test_scale(shape, 0.1_ud);
}

BOOST_AUTO_TEST_CASE(copy)
{
  dan::CompositeShape cpy(shape);

  BOOST_CHECK_EQUAL(shape.getArea(), cpy.getArea());
  equal_size(shape.getFrameRect(), cpy.getFrameRect());
  BOOST_CHECK_EQUAL(shape.getFrameRect().pos.x, cpy.getFrameRect().pos.x);
  BOOST_CHECK_EQUAL(shape.getFrameRect().pos.y, cpy.getFrameRect().pos.y);
}

BOOST_AUTO_TEST_SUITE_END()
