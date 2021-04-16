#include "test-functions.hpp"
#include "circle.hpp"
#include "exceptions.hpp"

BOOST_AUTO_TEST_SUITE(test_Circle)

  BOOST_AUTO_TEST_CASE(test_scale)
  {
    testScale(makeCircle());
  }
  BOOST_AUTO_TEST_CASE(test_move)
  {
    testMove(makeCircle());
  }
  BOOST_AUTO_TEST_CASE(test_shape_arg_exception)
  {
    BOOST_CHECK_THROW(pozdnyakov::Circle(-5, {3, 5}), ShapeArgException);
  }

BOOST_AUTO_TEST_SUITE_END()
