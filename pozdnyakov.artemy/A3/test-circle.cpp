#include "test-functions.hpp"
#include "circle.hpp"

namespace poz = pozdnyakov;

BOOST_AUTO_TEST_SUITE(test_Circle)

  BOOST_AUTO_TEST_CASE(test_scale)
  {
    testScale(makeCircle(88, poz::point_t{77, 13}));
  }
  BOOST_AUTO_TEST_CASE(test_move)
  {
    testMove(makeCircle(88, poz::point_t{77, 13}));
  }
  BOOST_AUTO_TEST_CASE(test_shape_arg_exception)
  {
    BOOST_CHECK_THROW(poz::Circle(-5, {3, 5}), std::invalid_argument);
  }

BOOST_AUTO_TEST_SUITE_END()
