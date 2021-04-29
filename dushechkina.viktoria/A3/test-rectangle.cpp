#include <boost/test/unit_test.hpp>
#include <stdexcept>
#include "test-function.hpp"
#include "rectangle.hpp"

namespace vika = dushechkina;

std::unique_ptr< vika::Rectangle > makingRectangle()
{
  return std::make_unique< vika::Rectangle >(vika::width1, vika::height1, vika::center);
}

BOOST_AUTO_TEST_SUITE(Rectangle)
BOOST_AUTO_TEST_CASE(ConstructorRectangle)
{
  BOOST_CHECK_CLOSE(getWidth(*makingRectangle()), vika::width1, vika::TOLERANCE);
  BOOST_CHECK_CLOSE(getHeight(*makingRectangle()), vika::height1, vika::TOLERANCE);
  BOOST_CHECK_CLOSE(getX(*makingRectangle()), vika::center.x, vika::TOLERANCE);
  BOOST_CHECK_CLOSE(getY(*makingRectangle()), vika::center.y, vika::TOLERANCE);
}

BOOST_AUTO_TEST_CASE(Rectangle_WidthLessZero_CreateObject)
{
  BOOST_CHECK_THROW(vika::Rectangle rectangle(vika::neg, vika:: height1, vika::center), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(Rectangle_HeightLessZero_CreateObject)
{
  BOOST_CHECK_THROW(vika::Rectangle rectangle(vika::width1, vika::neg, vika::center), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(Rectangle_ScaleLessZero_CreateObject)
{
  BOOST_CHECK_THROW(makingRectangle()->scale(vika::neg), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(MoveRectangle_InPoint_CorrectWorkMethod)
{
  checkBeforeCenterMoving(*makingRectangle());
}

BOOST_AUTO_TEST_CASE(MoveRectangle_XandYoffset_CorrectWorkMethod)
{
  checkBeforeDMoving(*makingRectangle());
}

BOOST_AUTO_TEST_CASE(scaleRectangle)
{
  checkBeforeScale(*makingRectangle());
}
BOOST_AUTO_TEST_SUITE_END()
