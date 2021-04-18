#include "test-functions.hpp"
#include "boost/test/unit_test.hpp"

namespace lab = shkurov;

BOOST_AUTO_TEST_SUITE(rectangle_test)

BOOST_AUTO_TEST_CASE(constructor_throw_exception)
{
  BOOST_CHECK_THROW(lab::makeBadRectangle(), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(move)
{
  lab::testMoveToPoint(*(lab::makeRectangle()));
}

BOOST_AUTO_TEST_CASE(scale)
{
  lab::testScale(*(lab::makeRectangle()));
}

BOOST_AUTO_TEST_CASE(scale_throw_exception)
{
  BOOST_CHECK_THROW(lab::invalidScale(*(lab::makeRectangle())), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END();
