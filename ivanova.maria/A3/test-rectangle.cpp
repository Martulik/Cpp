#include <boost/test/unit_test.hpp>
#include "test-func.hpp"
#include "rectangle.hpp"

double height = 9.0;
double width = 4.7;
ivanova::point_t pos{-8.3, 6.0};
BOOST_AUTO_TEST_SUITE(testRectangle)

BOOST_AUTO_TEST_CASE(moveRectangle)
{
  ivanova::Rectangle rectangle(height, width, pos);
  checkMoveAbs(&rectangle);
  checkMoveToPoint(&rectangle);
}

BOOST_AUTO_TEST_CASE(scaleRectangle)
{
  ivanova::Rectangle rectangle(height, width, pos);
  checkScale(&rectangle);
}

BOOST_AUTO_TEST_SUITE_END()
