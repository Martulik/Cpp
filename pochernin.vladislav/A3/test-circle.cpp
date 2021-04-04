#include <boost/test/unit_test.hpp>

#include "circle.hpp"
#include "test-functions.hpp"

const double radius = 200.0;
const double negativeValue = -10.0;
const pochernin::point_t startPos = {10.0, 20.0};

BOOST_AUTO_TEST_SUITE(Circle)

BOOST_AUTO_TEST_CASE(ConstWidthHeightAreaWhenMoving)
{
  pochernin::Circle testCircle(radius, startPos);
  pochernin::checkConstWidthHeightArea(&testCircle); 
}

BOOST_AUTO_TEST_CASE(QuadraticChangeAreaWhenScale)
{
  pochernin::Circle testCircle(radius, startPos);
  pochernin::checkQuadraticChangeAreaWhenScale(&testCircle);
}

BOOST_AUTO_TEST_CASE(HandlingIncorrectParameters)
{
  BOOST_CHECK_THROW(pochernin::Circle(negativeValue, startPos), std::invalid_argument);
  pochernin::Circle testCircle(radius, startPos);
  BOOST_CHECK_THROW(testCircle.scale(negativeValue), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END();
