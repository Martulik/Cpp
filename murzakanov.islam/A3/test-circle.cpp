#include "test-functions.hpp"

BOOST_AUTO_TEST_SUITE(test_Circle)

  BOOST_AUTO_TEST_CASE(test_move)
  {
    murzakanov::testMove(murzakanov::makeCircle());
  }

  BOOST_AUTO_TEST_CASE(test_scale)
  {
    murzakanov::testScale(murzakanov::makeCircle());
  }

  BOOST_AUTO_TEST_CASE(test_invalid_argument)
  {
    BOOST_CHECK_THROW(murzakanov::Circle(-1, {0, 0}), std::invalid_argument);
  }

BOOST_AUTO_TEST_SUITE_END()
