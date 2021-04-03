#include <boost/test/unit_test.hpp>
#include <stdexcept>
#include "test-function.hpp"
#include "rectangle.hpp"

namespace vika = dushechkina;

const double EPSILON = 0.00001;
const double width = 12.8;
const double height = 6.4;
const double negWidth = -12.8;
const double negHeight = -6.4;
const double negRatio = -5.0;
vika::point_t center = { -3.2, 0.8 };
vika::Rectangle rectangle(width, height, center);

BOOST_AUTO_TEST_SUITE(Rectangle)
BOOST_AUTO_TEST_CASE(ConstructorRectangle)
{
  BOOST_CHECK_CLOSE(getWidth(rectangle), width, EPSILON);
  BOOST_CHECK_CLOSE(getHeight(rectangle), height, EPSILON);
  BOOST_CHECK_CLOSE(getX(rectangle), center.x, EPSILON);
  BOOST_CHECK_CLOSE(getY(rectangle), center.y, EPSILON);
}

BOOST_AUTO_TEST_CASE(Rectangle_WidthLessZero_CreateObject)
{
  BOOST_CHECK_THROW(vika::Rectangle rectangle(negWidth, height, center), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(Rectangle_HeightLessZero_CreateObject)
{
  BOOST_CHECK_THROW(vika::Rectangle rectangle(width, negHeight, center), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(Rectangle_ScaleLessZero_CreateObject)
{
  BOOST_CHECK_THROW(rectangle.scale(negRatio), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(MoveRectangle_InPoint_CorrectWorkMethod)
{
  checkBeforeCenterMoving(&rectangle);
}

BOOST_AUTO_TEST_CASE(MoveRectangle_XandYoffset_CorrectWorkMethod)
{
  checkBeforeDMoving(&rectangle);
}

BOOST_AUTO_TEST_CASE(scaleRectangle)
{
  checkBeforeScale(&rectangle);
}
BOOST_AUTO_TEST_SUITE_END()
