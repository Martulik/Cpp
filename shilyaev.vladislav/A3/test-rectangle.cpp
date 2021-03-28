#include <boost/test/unit_test.hpp>
#include "rectangle.hpp"
#include "test-common.hpp"
#include "test-shape.hpp"

std::unique_ptr< shilyaev::Rectangle > makeRectangle()
{
  return std::make_unique< shilyaev::Rectangle >(WIDTH, HEIGHT, CENTER);
}

BOOST_AUTO_TEST_CASE(TestRectangle)
{
  testShape(*makeRectangle());
}

BOOST_AUTO_TEST_CASE(TestRectangleArea)
{
  const double expectedArea = HEIGHT * WIDTH;
  BOOST_CHECK_CLOSE(makeRectangle()->getArea(), expectedArea, TOLERANCE);
}

BOOST_AUTO_TEST_CASE(TestRectangleFrameRect)
{
  const shilyaev::rectangle_t expectedFrameRect{WIDTH, HEIGHT, CENTER};
  checkRectanglesClose(makeRectangle()->getFrameRect(), expectedFrameRect, TOLERANCE);
}

BOOST_AUTO_TEST_CASE(TestRectangleInvalidArgument)
{
  BOOST_CHECK_THROW(shilyaev::Rectangle rectangle(-WIDTH, HEIGHT, CENTER), std::invalid_argument);
  BOOST_CHECK_THROW(shilyaev::Rectangle rectangle(WIDTH, -HEIGHT, CENTER), std::invalid_argument);
}
