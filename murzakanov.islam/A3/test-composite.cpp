#include "test-functions.hpp"

BOOST_AUTO_TEST_SUITE(test_CompositeShape)

  BOOST_AUTO_TEST_CASE(test_move)
  {
    murzakanov::testMove(murzakanov::makeCompositeSh());
  }

  BOOST_AUTO_TEST_CASE(test_scale)
  {
    murzakanov::testScale(murzakanov::makeCompositeSh());
  }

  BOOST_AUTO_TEST_CASE(test_invalid_argument)
  {
    BOOST_CHECK_THROW(murzakanov::CompositeShape({}), std::invalid_argument);
  }

BOOST_AUTO_TEST_SUITE_END()
