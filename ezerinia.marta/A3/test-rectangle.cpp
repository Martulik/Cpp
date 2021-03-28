#include <boost/test/included/unit_test.hpp>
#include <stdexcept>
#include "test-tools.hpp"
#include "rectangle.hpp"

const double width = 1.0;
const double height = 2.0;
const double negativeValue = -1.0;
const ezerinia::point_t StartPos{1.0, -1.0};

namespace lab = ezerinia;

BOOST_AUTO_TEST_SUITE(testRectangle)

  BOOST_AUTO_TEST_CASE(moveRectangle)
  {
    lab::Rectangle rectangle(width, height, StartPos);
    checkMoveAbs(&rectangle);
    checkMovePoint(&rectangle);
  }

  BOOST_AUTO_TEST_CASE(scaleRectangle)
  {
    lab::Rectangle rectangle(width, height, StartPos);
    checkScale(&rectangle);
  }

  BOOST_AUTO_TEST_CASE(invalidArgumentRectangle)
  {
    BOOST_CHECK_THROW(lab::Rectangle(width, negativeValue, StartPos), std::invalid_argument);
    BOOST_CHECK_THROW(lab::Rectangle(negativeValue, height, StartPos), std::invalid_argument);
    BOOST_CHECK_THROW(lab::Rectangle(width, height, StartPos).scale(negativeValue), std::invalid_argument);
  }

BOOST_AUTO_TEST_SUITE_END()
