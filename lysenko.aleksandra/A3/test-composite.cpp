#include "test-functions.hpp"

BOOST_AUTO_TEST_SUITE(test_composite)

BOOST_AUTO_TEST_CASE(test_move)
{
  lysenko::testMove(lysenko::makeCompositeShape());
}

BOOST_AUTO_TEST_CASE(test_scale)
{
  lysenko::testScale(lysenko::makeCompositeShape());
}

BOOST_AUTO_TEST_CASE(test_default_shape)
{
  BOOST_CHECK_THROW(lysenko::CompositeShape myComposite(nullptr), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(test_popShape)
{
  lysenko::CompositeShape myComposite(lysenko::makeCircle());
  BOOST_CHECK_THROW(myComposite.popShape(), std::string);
}

BOOST_AUTO_TEST_SUITE_END()
