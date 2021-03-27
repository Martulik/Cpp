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
  dan::test_move_rel(circle, {1, 2});
  dan::test_move_rel(circle, {-5, 7});
  dan::test_move_abs(circle, {65, -33});
}

BOOST_AUTO_TEST_CASE(test_scale)
{
  dan::test_scale(circle, 3_ud);
  dan::test_scale(circle, 0.5_ud);
}

BOOST_AUTO_TEST_SUITE_END()
