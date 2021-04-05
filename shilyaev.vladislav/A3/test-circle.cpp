#include <boost/test/unit_test.hpp>
#include "circle.hpp"
#include "test-common.hpp"
#include "test-shape.hpp"

std::unique_ptr< shilyaev::Circle > makeCircle()
{
  return std::make_unique< shilyaev::Circle >(shilyaev::RADIUS, shilyaev::CENTER);
}

BOOST_AUTO_TEST_CASE(TestCircle)
{
  testShape(*makeCircle());
}

BOOST_AUTO_TEST_CASE(TestCircleArea)
{
  const double expectedArea = shilyaev::RADIUS * shilyaev::RADIUS * shilyaev::PI;
  BOOST_CHECK_CLOSE(makeCircle()->getArea(), expectedArea, shilyaev::TOLERANCE);
}

BOOST_AUTO_TEST_CASE(TestCircleFrameRect)
{
  const shilyaev::rectangle_t expectedFrameRect{shilyaev::RADIUS * 2,shilyaev::RADIUS * 2, shilyaev::CENTER};
  checkRectanglesClose(makeCircle()->getFrameRect(), expectedFrameRect, shilyaev::TOLERANCE);
}

BOOST_AUTO_TEST_CASE(TestCircleInvalidArgument)
{
  BOOST_CHECK_THROW(shilyaev::Circle circle(-shilyaev::RADIUS, shilyaev::CENTER), std::invalid_argument);
}
