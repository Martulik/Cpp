#include "test-functions.hpp"
#include "boost/test/unit_test.hpp"

namespace ss = shkurov;

BOOST_AUTO_TEST_SUITE(circle_test)

BOOST_AUTO_TEST_CASE(constructor_throw_exception)
{
  BOOST_CHECK_THROW(ss::makeBadCircle(), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(move)
{
  ss::testMoveToPoint(*(ss::makeCircle()));
}

BOOST_AUTO_TEST_CASE(scale_correct_modification)
{
  ss::testScale(*(ss::makeCircle()));
}

BOOST_AUTO_TEST_CASE(scale_throw_exception)
{
  BOOST_CHECK_THROW(ss::invalidScale(*(ss::makeCircle())), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END();
