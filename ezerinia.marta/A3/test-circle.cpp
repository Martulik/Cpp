#include <boost/test/included/unit_test.hpp>
#include <stdexcept>
#include "test-tools.hpp"
#include "circle.hpp"

namespace lab = ezerinia;

BOOST_AUTO_TEST_SUITE(testCircle)

  BOOST_AUTO_TEST_CASE(moveCircle)
  {
    lab::Circle circle(radius, StartPos);
    checkMoveAbs(&circle);
    checkMovePoint(&circle);
  }

  BOOST_AUTO_TEST_CASE(scaleCircle)
  {
    lab::Circle circle(radius, StartPos);
    checkScale(&circle);
  }

  BOOST_AUTO_TEST_CASE(invalidArgumentCircle)
  {
    BOOST_CHECK_THROW(lab::Circle(negativeValue, StartPos), std::invalid_argument);
    BOOST_CHECK_THROW(lab::Circle(radius, StartPos).scale(negativeValue), std::invalid_argument);
  }

BOOST_AUTO_TEST_SUITE_END()
