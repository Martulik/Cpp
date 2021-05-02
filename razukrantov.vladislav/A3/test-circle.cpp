#include <boost/test/unit_test.hpp>
#include "test-function.hpp"
#include "circle.hpp"

namespace razukrantov
{
  const double radius = 5.0;
  const double negativeValue = -1.0;
  const point_t startPos = {2.0, 4.0};
}

BOOST_AUTO_TEST_SUITE(Circle)

BOOST_AUTO_TEST_CASE(moveCircle)
{
  razukrantov::Circle circle(razukrantov::radius, razukrantov::startPos);
  razukrantov::checkDeltaMove(circle);
  razukrantov::checkPointMove(circle);
}

BOOST_AUTO_TEST_CASE(scaleCircle)
{
  razukrantov::Circle circle(razukrantov::radius, razukrantov::startPos);
  razukrantov::checkScale(circle);
}

BOOST_AUTO_TEST_CASE(incorrectParametrsCircle)
{
  BOOST_CHECK_THROW(razukrantov::Circle(razukrantov::negativeValue, razukrantov::startPos), std::invalid_argument);
  razukrantov::Circle circle(razukrantov::radius, razukrantov::startPos);
  BOOST_CHECK_THROW(circle.scale(razukrantov::negativeValue), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()
