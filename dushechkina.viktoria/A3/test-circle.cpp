#include <boost/test/unit_test.hpp>
#include "test-function.hpp"
#include "circle.hpp"

namespace vika = dushechkina;

const double EPSILON = 0.00001;
const vika::point_t centre = { 3.2, 6.4 };
const double rad = 20.48;
const double negValue = -8.0;
vika::Circle circle(centre, rad);

BOOST_AUTO_TEST_SUITE(Circle)
BOOST_AUTO_TEST_CASE(ConstructorCircle)
{
  BOOST_CHECK_CLOSE(getWidth(circle)/2, rad, EPSILON);
  BOOST_CHECK_CLOSE(getX(circle), centre.x, EPSILON);
  BOOST_CHECK_CLOSE(getY(circle), centre.y, EPSILON);
}

BOOST_AUTO_TEST_CASE(Circle_RadiusLessZero_CreateObject)
{
  BOOST_CHECK_THROW(vika::Circle circle(centre, negValue), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(Circle_ScaleLessZero_CreateObject)
{
  BOOST_CHECK_THROW(circle.scale(negValue), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(MoveCircle_XandYoffset_CorrectWorkMethod)
{
  checkBeforeDMoving(&circle);
}

BOOST_AUTO_TEST_CASE(MoveCircle_InPoint_CorrectWorkMethod)
{
  checkBeforeCenterMoving(&circle);
}

BOOST_AUTO_TEST_CASE(scaleCircle)
{
  checkBeforeScale(&circle);
}

BOOST_AUTO_TEST_SUITE_END()
