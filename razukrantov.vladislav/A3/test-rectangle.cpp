#include <boost/test/unit_test.hpp>
#include "test-function.hpp"
#include "rectangle.hpp"

namespace razukrantov
{
  const double width = 5.0;
  const double height = 3.0;
  const double negativeValue = -1.0;
  const point_t startPos = {10.0, 15.0};
}

BOOST_AUTO_TEST_SUITE(Rectangle)

BOOST_AUTO_TEST_CASE(moveRectangle)
{
  razukrantov::Rectangle rectangle(razukrantov::width, razukrantov::height, razukrantov::startPos);
  razukrantov::checkDeltaMove(rectangle);
  razukrantov::checkPointMove(rectangle);
}

BOOST_AUTO_TEST_CASE(scaleRectangle)
{
  razukrantov::Rectangle rectangle(razukrantov::width, razukrantov::height, razukrantov::startPos);
  razukrantov::checkScale(rectangle);
}

BOOST_AUTO_TEST_CASE(incorrectParametrsRectangle)
{
  BOOST_CHECK_THROW(razukrantov::Rectangle(razukrantov::negativeValue, razukrantov::height, razukrantov::startPos), std::invalid_argument);
  BOOST_CHECK_THROW(razukrantov::Rectangle(razukrantov::width, razukrantov::negativeValue, razukrantov::startPos), std::invalid_argument);
  razukrantov::Rectangle rectangle(razukrantov::width, razukrantov::height, razukrantov::startPos);
  BOOST_CHECK_THROW(rectangle.scale(razukrantov::negativeValue), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()
