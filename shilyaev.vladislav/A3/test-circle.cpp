#include <boost/test/unit_test.hpp>
#include "circle.hpp"
#include "test-common.hpp"
#include "test-shape.hpp"

std::unique_ptr< shilyaev::Circle > makeCircle()
{
  return std::make_unique< shilyaev::Circle >(RADIUS, CENTER);
}

BOOST_AUTO_TEST_CASE(TestCircle)
{
  testShape(*makeCircle());
}

BOOST_AUTO_TEST_CASE(TestCircleArea)
{
  const double expectedArea = RADIUS * RADIUS * PI;
  BOOST_CHECK_CLOSE(makeCircle()->getArea(), expectedArea, TOLERANCE);
}

BOOST_AUTO_TEST_CASE(TestCircleFrameRect)
{
  const shilyaev::rectangle_t expectedFrameRect{RADIUS * 2, RADIUS * 2, CENTER};
  checkRectanglesClose(makeCircle()->getFrameRect(), expectedFrameRect, TOLERANCE);
}

BOOST_AUTO_TEST_CASE(TestCircleInvalidArgument)
{
  BOOST_CHECK_THROW(shilyaev::Circle circle(-RADIUS, CENTER), std::invalid_argument);
}
