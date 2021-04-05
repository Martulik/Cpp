#include "test-functions.hpp"

BOOST_AUTO_TEST_SUITE(test_circle)
  
BOOST_AUTO_TEST_CASE(test_move)
{
  lysenko::testMove(lysenko::makeCircle());
}

BOOST_AUTO_TEST_CASE(test_scale)
{
  lysenko::testScale(lysenko::makeCircle());
}

BOOST_AUTO_TEST_CASE(test_invalid_radius)
{
  BOOST_CHECK_THROW(lysenko::Circle myCircle({ 1.0, 1.0}, -33.33), std::invalid_argument);
}


BOOST_AUTO_TEST_SUITE_END()
