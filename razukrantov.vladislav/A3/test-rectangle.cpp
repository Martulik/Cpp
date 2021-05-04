#include <boost/test/unit_test.hpp>
#include "test-function.hpp"
#include "rectangle.hpp"

namespace raz = razukrantov;
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
  raz::Rectangle rectangle(raz::width, raz::height, raz::startPos);
  raz::checkDeltaMove(rectangle);
  raz::checkPointMove(rectangle);
}

BOOST_AUTO_TEST_CASE(scaleRectangle)
{
  raz::Rectangle rectangle(raz::width, raz::height, raz::startPos);
  raz::checkScale(rectangle);
}

BOOST_AUTO_TEST_CASE(incorrectParametrsRectangle)
{
  BOOST_CHECK_THROW(raz::Rectangle(raz::negativeValue, raz::height, raz::startPos), std::invalid_argument);
  BOOST_CHECK_THROW(raz::Rectangle(raz::width, raz::negativeValue, raz::startPos), std::invalid_argument);
  raz::Rectangle rectangle(raz::width, raz::height, raz::startPos);
  BOOST_CHECK_THROW(rectangle.scale(raz::negativeValue), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()
