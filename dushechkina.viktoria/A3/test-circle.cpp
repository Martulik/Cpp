#include <boost/test/unit_test.hpp>
#include "test-function.hpp"
#include "circle.hpp"

namespace vika = dushechkina;

std::unique_ptr< vika::Circle > makingCircle()
{
  return std::make_unique< vika::Circle >(vika::center, vika::radius1);
}

BOOST_AUTO_TEST_SUITE(Circle)
BOOST_AUTO_TEST_CASE(ConstructorCircle)
{
  BOOST_CHECK_CLOSE(getWidth(*makingCircle()) / 2, vika::radius1, vika::TOLERANCE);
  BOOST_CHECK_CLOSE(getX(*makingCircle()), vika::center.x, vika::TOLERANCE);
  BOOST_CHECK_CLOSE(getY(*makingCircle()), vika::center.y, vika::TOLERANCE);
}

BOOST_AUTO_TEST_CASE(Circle_RadiusLessZero_CreateObject)
{
  BOOST_CHECK_THROW(vika::Circle circle(vika::center, vika::neg), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(Circle_ScaleLessZero_CreateObject)
{
  BOOST_CHECK_THROW(makingCircle()->scale(vika::neg), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(MoveCircle_XandYoffset_CorrectWorkMethod)
{
  checkBeforeDMoving(*makingCircle());
}

BOOST_AUTO_TEST_CASE(MoveCircle_InPoint_CorrectWorkMethod)
{
  checkBeforeCenterMoving(*makingCircle());
}

BOOST_AUTO_TEST_CASE(scaleCircle)
{
  checkBeforeScale(*makingCircle());
}

BOOST_AUTO_TEST_SUITE_END()
