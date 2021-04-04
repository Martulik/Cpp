#include "test-functions.hpp"

BOOST_AUTO_TEST_CASE(scale_invalid_arguments)
{
  murzakanov::Rectangle rect(2, 1, {0, 0});
  BOOST_CHECK_THROW(rect.scale(-13), std::invalid_argument);
}
