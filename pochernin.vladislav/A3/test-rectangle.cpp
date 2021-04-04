#include <boost/test/unit_test.hpp>

#include "rectangle.hpp"
#include "test-functions.hpp"

const double width = 100.0;
const double height = 50.0;
const double negativeValue = - 10.0;
const pochernin::point_t startPos = {10.0, 20.0};

BOOST_AUTO_TEST_SUITE(Rectangle)

BOOST_AUTO_TEST_CASE(ConstWidthHeightAreaWhenMoving)
{
  pochernin::Rectangle testRectangle(width, height, startPos);
  pochernin::checkConstWidthHeightArea(&testRectangle);
}

BOOST_AUTO_TEST_CASE(QuadraticChangeAreaWhenScale)
{
  pochernin::Rectangle testRectangle(width, height, startPos);
  pochernin::checkQuadraticChangeAreaWhenScale(&testRectangle);
}

BOOST_AUTO_TEST_CASE(HandlingIncorrectParameters)
{
  BOOST_CHECK_THROW(pochernin::Rectangle(negativeValue, height, startPos), std::invalid_argument);
  BOOST_CHECK_THROW(pochernin::Rectangle(width, negativeValue, startPos), std::invalid_argument);
  pochernin::Rectangle testRectangle(width, height, startPos);
  BOOST_CHECK_THROW(testRectangle.scale(negativeValue), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()
