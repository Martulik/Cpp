#include <boost/test/unit_test.hpp>
#include <stdexcept>
#include "test-functions.hpp"

namespace leb = lebedeva;

BOOST_AUTO_TEST_SUITE(RectangleTest)

  BOOST_AUTO_TEST_CASE(invalidArgumentsRectangle)
  {
    BOOST_CHECK_THROW(leb::Rectangle a(lebedeva::pos, leb::width, leb::nHeight), std::invalid_argument);
    BOOST_CHECK_THROW(leb::Rectangle b(leb::pos, leb::nWidth, leb::height), std::invalid_argument);
    BOOST_CHECK_THROW(leb::makeRectangle()->scale(leb::nParameter), std::invalid_argument);
  }

  BOOST_AUTO_TEST_CASE(GetRectangleName)
  {
    leb::checkName("Rectangle", leb::makeRectangle()->getName());
  }

  BOOST_AUTO_TEST_CASE(MoveRectangle)
  {
    leb::checkMoveAbs(*leb::makeRectangle(), leb::newPos);
    leb::checkMoveToPoint(*leb::makeRectangle(), leb::newPos);
  }

  BOOST_AUTO_TEST_CASE(ScaleRectangle)
  {
    leb::checkScale(*leb::makeRectangle(), leb::parameter);
  }

BOOST_AUTO_TEST_SUITE_END()
