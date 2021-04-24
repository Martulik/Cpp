#include "test-functions.hpp"

BOOST_AUTO_TEST_SUITE(test_scale)

BOOST_AUTO_TEST_CASE(test_invalid_k)
{
  BOOST_CHECK_THROW(lysenko::makeCircle()->scale(-5), std::invalid_argument);
  BOOST_CHECK_THROW(lysenko::makeRectangle()->scale(-5), std::invalid_argument);
  BOOST_CHECK_THROW(lysenko::makeCompositeShape()->scale(-5), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()
