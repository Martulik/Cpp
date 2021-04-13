#include "test-functions.hpp"
#include "boost/test/unit_test.hpp"

BOOST_AUTO_TEST_SUITE(circle_test)

std::unique_ptr< shkurov::Shape > circle_ptr = shkurov::makeCircle();

BOOST_AUTO_TEST_CASE(constructor_throw_exception)
{
  BOOST_CHECK_THROW(shkurov::makeBadCircle(), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(move)
{
  shkurov::testMoveToPoint(*circle_ptr);
}

BOOST_AUTO_TEST_CASE(scale_correct_modification)
{
  shkurov::testScale(*circle_ptr);
}

BOOST_AUTO_TEST_CASE(scale_throw_exception)
{
  BOOST_CHECK_THROW(shkurov::invalidScale(*circle_ptr), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END();
