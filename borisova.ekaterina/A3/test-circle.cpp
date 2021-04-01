#include <boost/test/unit_test.hpp>
#include <stdexcept>
#include "test-functions.hpp"
#include "circle.hpp"

namespace lab = borisova;
using exc = std::invalid_argument;

BOOST_AUTO_TEST_SUITE(testCircle)

const double param1 = 4.12;
const double param2 = 91.004;
const double negParam = -12.91;

lab::point_t point1{ 0.4, 2.56 };
lab::point_t point2{ 65.03, 0.99 };

BOOST_AUTO_TEST_CASE(testParametersCir)
{
  BOOST_CHECK_THROW(lab::Circle circle1(point1, negParam), exc);
}

BOOST_AUTO_TEST_CASE(testAreaAfterMovingCir)
{
  areaAfterMoving(makeCircle(point1, param1));
}

BOOST_AUTO_TEST_CASE(testParamAfterMovingCir)
{
  paramAfterMoving(makeCircle(point2, param1));
}

BOOST_AUTO_TEST_CASE(testScaleCir)
{
  areaAfterScale(makeCircle(point1, param2));
}

BOOST_AUTO_TEST_CASE(testNameCir)
{
  lab::Shape* temp = makeCircle(point1, param2);
  BOOST_REQUIRE_EQUAL(temp->getName(), "Circle");
  delete temp;
}

BOOST_AUTO_TEST_SUITE_END()
