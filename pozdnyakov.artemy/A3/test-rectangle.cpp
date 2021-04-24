#include "test-functions.hpp"
#include "rectangle.hpp"

namespace poz = pozdnyakov;

BOOST_AUTO_TEST_SUITE(test_Rectangle)

  BOOST_AUTO_TEST_CASE(test_scale)
  {
    testScale(makeRect(99.3, 7, poz::point_t{13, 12}));
  }
  BOOST_AUTO_TEST_CASE(test_move)
  {
    testMove(makeRect(99.3, 7, poz::point_t{13, 12}));
  }
  BOOST_AUTO_TEST_CASE(test_shape_arg_exception)
  {
    BOOST_CHECK_THROW(poz::Rectangle(-8, -14, {0, 0}), std::invalid_argument);
  }

BOOST_AUTO_TEST_SUITE_END()
