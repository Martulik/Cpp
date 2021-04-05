#include <boost/test/unit_test.hpp>
#include <stdexcept>
#include "test-functions.hpp"
#include "test-variables.hpp"
#include "circle.hpp"

namespace lab = borisova;
using exc = std::invalid_argument;

BOOST_AUTO_TEST_SUITE(testCircle)

BOOST_AUTO_TEST_CASE(testParametersCir)
{
  BOOST_CHECK_THROW(lab::Circle circle1(lab::point1, lab::negParam), exc);
}

BOOST_AUTO_TEST_CASE(testAreaAfterMovingCir)
{
  areaAfterMoving(makeCircle(lab::point1, lab::param1));
}

BOOST_AUTO_TEST_CASE(testParamAfterMovingCir)
{
  paramAfterMoving(makeCircle(lab::point2, lab::param1));
}

BOOST_AUTO_TEST_CASE(testScaleCir)
{
  areaAfterScale(makeCircle(lab::point1, lab::param2));
}

BOOST_AUTO_TEST_CASE(testNameCir)
{
  BOOST_REQUIRE_EQUAL(makeCircle(lab::point1, lab::param2)->getName(), "Circle");
}

BOOST_AUTO_TEST_SUITE_END()
