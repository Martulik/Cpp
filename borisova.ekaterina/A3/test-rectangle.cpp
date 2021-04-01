#include <boost/test/unit_test.hpp>
#include <stdexcept>
#include "test-functions.hpp"
#include "rectangle.hpp"

namespace lab = borisova;
using exc = std::invalid_argument;

BOOST_AUTO_TEST_SUITE(testRectangle)

const double width = 11.5;
const double height = 0.01;
const double param1 = 4.12;
const double param2 = 91.004;
const double negParam = -12.91;
const lab::point_t point1{ 0.4, 2.56 };
const lab::point_t point2{ 65.03, 0.99 };

BOOST_AUTO_TEST_CASE(testParametersRec)
{
  BOOST_CHECK_THROW(lab::Rectangle rect1(point1, negParam, height), exc);
  BOOST_CHECK_THROW(lab::Rectangle rect2(point2.x, point2.y, width, negParam), exc);
}

BOOST_AUTO_TEST_CASE(testAreaAfterMovingRec)
{
  areaAfterMoving(&makeRectangle(point1, width, height));
}

BOOST_AUTO_TEST_CASE(testParamAfterMovingRec)
{
  paramAfterMoving(&makeRectangle(point2, width, param2));
}
BOOST_AUTO_TEST_CASE(testScaleRec)
{
  areaAfterScale(&makeRectangle(point1, param1, height));
}

BOOST_AUTO_TEST_CASE(testNameRec)
{
  BOOST_REQUIRE_EQUAL(makeRectangle(point2, param1, param2).getName(), "Rectangle");
}

BOOST_AUTO_TEST_SUITE_END()
