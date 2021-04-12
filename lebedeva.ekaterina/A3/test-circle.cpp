#include <boost/test/unit_test.hpp>
#include <stdexcept>
#include "test-functions.hpp"

namespace leb = lebedeva;

BOOST_AUTO_TEST_SUITE(CircleTest)

  BOOST_AUTO_TEST_CASE(invalidArgumentsCircle)
  {
    BOOST_CHECK_THROW(leb::Circle a(leb::pos, leb::nRadius), std::invalid_argument);
    BOOST_CHECK_THROW(leb::makeCircle()->scale(leb::nParameter), std::invalid_argument);
  }

  BOOST_AUTO_TEST_CASE(GetCircleName)
  {
    leb::checkName("Circle", leb::makeCircle()->getName());
  }

  BOOST_AUTO_TEST_CASE(MoveCircle)
  {
    leb::checkMoveAbs(*leb::makeCircle(), leb::newPos);
    leb::checkMoveToPoint(*leb::makeCircle(), leb::newPos);
  }

  BOOST_AUTO_TEST_CASE(ScaleCircle)
  {
    leb::checkScale(*leb::makeCircle(), leb::parameter);
  }

BOOST_AUTO_TEST_SUITE_END()
