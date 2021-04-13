#include "test-functions.hpp"
#include "boost/test/unit_test.hpp"

BOOST_AUTO_TEST_SUITE(circle_test)

BOOST_AUTO_TEST_CASE(constructor_throw_exception)
{
  BOOST_CHECK_THROW(shkurov::makeBadCircle(), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(move)
{
  shkurov::testMoveToPoint(*(shkurov::makeCircle()));
}

BOOST_AUTO_TEST_CASE(scale_correct_modification)
{
  shkurov::testScale(*(shkurov::makeCircle()));
}

BOOST_AUTO_TEST_CASE(scale_throw_exception)
{
  BOOST_CHECK_THROW(shkurov::invalidScale(*(shkurov::makeCircle())), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END();
