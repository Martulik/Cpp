#include "test-functions.hpp"

BOOST_AUTO_TEST_SUITE(test_CompositeShape)
  BOOST_AUTO_TEST_CASE(test_size_immutabilty)
  {
    pozdnyakov::UniqueShape cshape = pozdnyakov::makeCompositeShape();
    pozdnyakov::rectangle_t frame1 = cshape->getFrameRect();
    cshape->move(1, 1);
    pozdnyakov::rectangle_t frame2 = cshape->getFrameRect();
    bool sizeEq = frame1.width == frame2.width && frame1.height == frame2.height;
    bool posEq = frame1.pos.x == frame2.pos.x && frame1.pos.y == frame2.pos.y;
    BOOST_REQUIRE(sizeEq && posEq);
  }
BOOST_AUTO_TEST_SUITE_END()
