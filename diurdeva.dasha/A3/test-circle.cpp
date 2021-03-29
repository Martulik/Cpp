#include <boost/test/unit_test.hpp>
#include "test-function.hpp"
#include "circle.hpp"

const diurdeva::point_t pointCenter = { 3.5, 4.0 };
const double radius = 3.0;
const double negativeOptions = -8.0;

BOOST_AUTO_TEST_SUITE(testCircle)

BOOST_AUTO_TEST_CASE(invalidOptionsCircle)
{
  BOOST_CHECK_THROW(diurdeva::Circle(negativeOptions, pointCenter), std::invalid_argument);
  BOOST_CHECK_THROW(diurdeva::Circle(radius, pointCenter).scale(negativeOptions), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(moveCircle)
{
  diurdeva::Circle circle(radius, pointCenter);
  checkConstOptionsBeforeMoving(&circle);
}

BOOST_AUTO_TEST_CASE(scaleCircle)
{
  diurdeva::Circle circle(radius, pointCenter);
  checkAreaBeforeScale(&circle);
}

BOOST_AUTO_TEST_SUITE_END()
