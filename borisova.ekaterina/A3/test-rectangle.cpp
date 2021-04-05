#include <boost/test/unit_test.hpp>
#include <stdexcept>
#include "test-functions.hpp"
#include "test-variables.hpp"
#include "rectangle.hpp"

namespace lab = borisova;
using exc = std::invalid_argument;

BOOST_AUTO_TEST_SUITE(testRectangle)

BOOST_AUTO_TEST_CASE(testParametersRec)
{
  BOOST_CHECK_THROW(lab::Rectangle rect1(lab::point1, lab::negParam, lab::height), exc);
  BOOST_CHECK_THROW(lab::Rectangle rect2(lab::point2.x, lab::point2.y, lab::width, lab::negParam), exc);
}

BOOST_AUTO_TEST_CASE(testAreaAfterMovingRec)
{
  areaAfterMoving(makeRectangle(lab::point1, lab::width, lab::height));
}

BOOST_AUTO_TEST_CASE(testParamAfterMovingRec)
{
  paramAfterMoving(makeRectangle(lab::point2, lab::width, lab::param2));
}
BOOST_AUTO_TEST_CASE(testScaleRec)
{
  areaAfterScale(makeRectangle(lab::point1, lab::param1, lab::height));
}

BOOST_AUTO_TEST_CASE(testNameRec)
{
  BOOST_REQUIRE_EQUAL(makeRectangle(lab::point2, lab::param1, lab::param2)->getName(), "Rectangle");
}

BOOST_AUTO_TEST_SUITE_END()
