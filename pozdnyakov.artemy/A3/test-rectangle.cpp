#include "test-functions.hpp"
#include "rectangle.hpp"
#include "exceptions.hpp"

namespace poz = pozdnyakov;

BOOST_AUTO_TEST_SUITE(test_Rectangle)

  BOOST_AUTO_TEST_CASE(test_scale)
  {
    testScale(makeRect());
  }
  BOOST_AUTO_TEST_CASE(test_move)
  {
    testMove(makeRect());
  }
  BOOST_AUTO_TEST_CASE(test_shape_arg_exception)
  {
    BOOST_CHECK_THROW(poz::Rectangle(-8, -14, {0, 0}), ShapeArgException);
  }

BOOST_AUTO_TEST_SUITE_END()
