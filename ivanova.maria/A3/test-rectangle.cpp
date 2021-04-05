#include <boost/test/unit_test.hpp>
#include "test-func.hpp"
#include "rectangle.hpp"

double height = 9.0;
double width = 4.7;
ivanova::point_t pos{-8.3, 6.0};

std::unique_ptr< ivanova::Rectangle > makeRectangle()
{
  return std::make_unique< ivanova::Rectangle >(width, height, pos);
}

BOOST_AUTO_TEST_SUITE(testRectangle)

BOOST_AUTO_TEST_CASE(moveRectangle)
{
  checkMoveAbs(*makeRectangle());
  checkMoveToPoint(*makeRectangle());
}

BOOST_AUTO_TEST_CASE(scaleRectangle)
{
  checkScale(*makeRectangle());
}

BOOST_AUTO_TEST_SUITE_END()
