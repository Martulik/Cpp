#include "test-functions.hpp"
#include "boost/test/unit_test.hpp"

BOOST_AUTO_TEST_SUITE(rectangle_test)

std::unique_ptr< shkurov::Shape > rect_ptr = shkurov::makeRectangle();

BOOST_AUTO_TEST_CASE(constructor_throw_exception)
{
  BOOST_CHECK_THROW(shkurov::makeBadCircle(), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(move)
{
  shkurov::testMoveToPoint(*rect_ptr);
}

BOOST_AUTO_TEST_CASE(scale)
{
  shkurov::testScale(*rect_ptr);
}

BOOST_AUTO_TEST_CASE(scale_throw_exception)
{
  BOOST_CHECK_THROW(shkurov::invalidScale(*rect_ptr), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END();
