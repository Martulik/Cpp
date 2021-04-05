#include <boost/test/unit_test.hpp>
#include "rectangle.hpp"
#include "test-common.hpp"
#include "test-shape.hpp"

namespace shilyaev {
  std::unique_ptr< Rectangle > makeRectangle()
  {
    return std::make_unique< Rectangle >(WIDTH, HEIGHT, CENTER);
  }
}

BOOST_AUTO_TEST_CASE(TestRectangle)
{
  testShape(*shilyaev::makeRectangle());
}

BOOST_AUTO_TEST_CASE(TestRectangleArea)
{
  const double expectedArea = shilyaev::HEIGHT * shilyaev::WIDTH;
  BOOST_CHECK_CLOSE(shilyaev::makeRectangle()->getArea(), expectedArea, shilyaev::TOLERANCE);
}

BOOST_AUTO_TEST_CASE(TestRectangleFrameRect)
{
  const shilyaev::rectangle_t expectedFrameRect{shilyaev::WIDTH, shilyaev::HEIGHT, shilyaev::CENTER};
  checkRectanglesClose(shilyaev::makeRectangle()->getFrameRect(), expectedFrameRect, shilyaev::TOLERANCE);
}

BOOST_AUTO_TEST_CASE(TestRectangleInvalidArgument)
{
  namespace shi = shilyaev;
  BOOST_CHECK_THROW(shi::Rectangle r(-shi::WIDTH, shi::HEIGHT, shi::CENTER), std::invalid_argument);
  BOOST_CHECK_THROW(shi::Rectangle r(shi::WIDTH, -shi::HEIGHT, shi::CENTER), std::invalid_argument);
}
