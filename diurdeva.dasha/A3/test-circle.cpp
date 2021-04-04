#include <boost/test/unit_test.hpp>
#include "test-function.hpp"
#include "circle.hpp"

const diurdeva::point_t pointCenter = { 3.5, 4.0 };
const double radius = 3.0;
const double negativeOptions = -8.0;

std::unique_ptr< diurdeva::Circle > makeCircle()
{
  return std::make_unique< diurdeva::Circle >(radius, pointCenter);
}

BOOST_AUTO_TEST_SUITE(testCircle)

BOOST_AUTO_TEST_CASE(invalidOptionsCircle)
{
  BOOST_CHECK_THROW(diurdeva::Circle(negativeOptions, pointCenter), std::invalid_argument);
  BOOST_CHECK_THROW(diurdeva::Circle(radius, pointCenter).scale(negativeOptions), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(moveCircle)
{
  checkConstOptionsBeforeMoving(*makeCircle());
}

BOOST_AUTO_TEST_CASE(scaleCircle)
{
  checkAreaBeforeScale(*makeCircle());
}

BOOST_AUTO_TEST_SUITE_END()
