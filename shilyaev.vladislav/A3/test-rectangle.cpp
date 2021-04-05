#include <boost/test/unit_test.hpp>
#include "rectangle.hpp"
#include "test-common.hpp"
#include "test-shape.hpp"

std::unique_ptr< shilyaev::Rectangle > makeRectangle()
{
  return std::make_unique< shilyaev::Rectangle >(shilyaev::WIDTH, shilyaev::HEIGHT, shilyaev::CENTER);
}

BOOST_AUTO_TEST_CASE(TestRectangle)
{
  testShape(*makeRectangle());
}

BOOST_AUTO_TEST_CASE(TestRectangleArea)
{
  const double expectedArea = shilyaev::HEIGHT * shilyaev::WIDTH;
  BOOST_CHECK_CLOSE(makeRectangle()->getArea(), expectedArea, shilyaev::TOLERANCE);
}

BOOST_AUTO_TEST_CASE(TestRectangleFrameRect)
{
  const shilyaev::rectangle_t expectedFrameRect{shilyaev::WIDTH, shilyaev::HEIGHT, shilyaev::CENTER};
  checkRectanglesClose(makeRectangle()->getFrameRect(), expectedFrameRect, shilyaev::TOLERANCE);
}

BOOST_AUTO_TEST_CASE(TestRectangleInvalidArgument)
{
  namespace shi = shilyaev;
  BOOST_CHECK_THROW(shi::Rectangle r(-shi::WIDTH, shi::HEIGHT, shi::CENTER), std::invalid_argument);
  BOOST_CHECK_THROW(shi::Rectangle r(shi::WIDTH, -shi::HEIGHT, shi::CENTER), std::invalid_argument);
}
