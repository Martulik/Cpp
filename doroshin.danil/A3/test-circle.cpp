#include <boost/test/unit_test.hpp>
#include "test-utility.hpp"
#include "circle.hpp"

namespace dan = doroshin;
using namespace dan::literals;

struct CircleTestFixture
{
  CircleTestFixture():
    circle{{1, 2}, 3_ud}
  {}

  dan::Circle circle;
};

BOOST_FIXTURE_TEST_SUITE(Circle, CircleTestFixture)

BOOST_AUTO_TEST_CASE(test_move)
{
  dan::testMoveRel(circle, {1, 2});
  dan::testMoveRel(circle, {-5, 7});
  dan::testMoveAbs(circle, {65, -33});
}

BOOST_AUTO_TEST_CASE(test_scale)
{
  dan::testScale(circle, 3_ud);
  dan::testScale(circle, 0.5_ud);
}

BOOST_AUTO_TEST_SUITE_END()
