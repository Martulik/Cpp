#include <boost/test/unit_test.hpp>
#include "test-func.hpp"
#include "circle.hpp"

const double radius = 4.0;
const ivanova::point_t ctr = {2.1, 7.0};

BOOST_AUTO_TEST_SUITE(testCircle)

BOOST_AUTO_TEST_CASE(moveCircle)
{
  ivanova::Circle circle(ctr, radius);
  checkMoveAbs(&circle);
  checkMoveToPoint(&circle);
}

BOOST_AUTO_TEST_CASE(scaleCircle)
{
  ivanova::Circle circle(ctr, radius);
  checkScale(&circle);
}

BOOST_AUTO_TEST_SUITE_END()
