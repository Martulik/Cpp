#include <boost/test/unit_test.hpp>

#include "test-functions.hpp"

namespace fer = ferapontov;

BOOST_AUTO_TEST_SUITE(TestCircle)

BOOST_AUTO_TEST_CASE(TestMove)
{
  fer::Circle circ = fer::makeCircle();
  fer::test_move(circ, {-1, -1});
  fer::test_move(circ, -1, -1);
}

BOOST_AUTO_TEST_CASE(TestScale)
{
  fer::Circle circ = fer::makeCircle();
  fer::test_scale(circ, 2);
}

BOOST_AUTO_TEST_CASE(TestInvalidArgument)
{
  fer::Circle circ = fer::makeCircle();
  fer::test_invalid_argument(circ, -2);
}

BOOST_AUTO_TEST_SUITE_END()
