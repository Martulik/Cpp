#include "test-functions.hpp"

BOOST_AUTO_TEST_SUITE(test_scale)

BOOST_AUTO_TEST_CASE(test_invalid_k)
{
  lysenko::Circle myCircle({ 1.0, 1.0 }, 33.33);
  BOOST_CHECK_THROW(myCircle.scale(-5), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()
