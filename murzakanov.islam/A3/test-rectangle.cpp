#include "test-functions.hpp"

BOOST_AUTO_TEST_SUITE(test_Rectangle)

  BOOST_AUTO_TEST_CASE(test_move)
  {
    murzakanov::testMove(murzakanov::makeRect());
  }

  BOOST_AUTO_TEST_CASE(test_scale)
  {
    murzakanov::testScale(murzakanov::makeRect());
  }

  BOOST_AUTO_TEST_CASE(test_invalid_argument)
  {
    BOOST_CHECK_THROW(murzakanov::Rectangle(-3.7, 2.2, {12, 13}), std::invalid_argument);
  }

BOOST_AUTO_TEST_SUITE_END()
