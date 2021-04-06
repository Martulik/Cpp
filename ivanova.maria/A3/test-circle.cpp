#include <boost/test/unit_test.hpp>
#include "test-func.hpp"
#include "circle.hpp"

const double radius = 4.0;
const ivanova::point_t ctr = {2.1, 7.0};

std::unique_ptr< ivanova::Circle > makeCircle()
{
  return std::make_unique< ivanova::Circle >(ctr, radius);
}

BOOST_AUTO_TEST_SUITE(testCircle)

BOOST_AUTO_TEST_CASE(moveCircle)
{
  checkMoveAbs(*makeCircle());
  checkMoveToPoint(*makeCircle());
}

BOOST_AUTO_TEST_CASE(scaleCircle)
{
  checkScale(*makeCircle());
}

BOOST_AUTO_TEST_SUITE_END()
