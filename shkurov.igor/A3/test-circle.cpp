#include "test-functions.hpp"
#include "boost/test/unit_test.hpp"

namespace lab = shkurov;

BOOST_AUTO_TEST_SUITE(circle_test)

BOOST_AUTO_TEST_CASE(constructor_throw_exception)
{
  BOOST_CHECK_THROW(lab::makeBadCircle(), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(move)
{
  lab::testMoveToPoint(*(lab::makeCircle()));
}

BOOST_AUTO_TEST_CASE(scale_correct_modification)
{
  lab::testScale(*(lab::makeCircle()));
}

BOOST_AUTO_TEST_CASE(scale_throw_exception)
{
  BOOST_CHECK_THROW(lab::invalidScale(*(lab::makeCircle())), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END();
