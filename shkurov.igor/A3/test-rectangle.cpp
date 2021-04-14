#include "test-functions.hpp"
#include "boost/test/unit_test.hpp"

namespace ss = shkurov;

BOOST_AUTO_TEST_SUITE(rectangle_test)

BOOST_AUTO_TEST_CASE(constructor_throw_exception)
{
  BOOST_CHECK_THROW(ss::makeBadRectangle(), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(move)
{
  ss::testMoveToPoint(*(ss::makeRectangle()));
}

BOOST_AUTO_TEST_CASE(scale)
{
  ss::testScale(*(ss::makeRectangle()));
}

BOOST_AUTO_TEST_CASE(scale_throw_exception)
{
  BOOST_CHECK_THROW(ss::invalidScale(*(ss::makeRectangle())), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END();
