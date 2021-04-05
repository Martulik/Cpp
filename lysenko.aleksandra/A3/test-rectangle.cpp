#include "test-functions.hpp"

BOOST_AUTO_TEST_SUITE(test_rectangle)

BOOST_AUTO_TEST_CASE(test_move)
{
  lysenko::testMove(lysenko::makeRectangle());
}

BOOST_AUTO_TEST_CASE(test_scale)
{
  lysenko::testScale(lysenko::makeRectangle());
}

BOOST_AUTO_TEST_CASE(test_invalid_width)
{
  BOOST_CHECK_THROW(lysenko::Rectangle myRectangle(-1.0, 2.0, {33.33, 33.33}), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(test_invalid_height)
{
  BOOST_CHECK_THROW(lysenko::Rectangle myRectangle( 1.0, - 2.0, {33.33, 33.33}), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(test_invalid_weight_and_height)
{
  BOOST_CHECK_THROW(lysenko::Rectangle myRectangle(-1.0, -2.0, { 33.33, 33.33 }), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()
