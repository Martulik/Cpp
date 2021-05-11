#include "test-functions.hpp"
#include "composite-shape.hpp"

namespace poz = pozdnyakov;

BOOST_AUTO_TEST_SUITE(test_CompositeShape)

  BOOST_AUTO_TEST_CASE(test_scale)
  {
    testScale(makeCompositeShape());
  }
  BOOST_AUTO_TEST_CASE(test_move)
  {
    testMove(makeCompositeShape());
  }
  BOOST_AUTO_TEST_CASE(test_shape_arg_exception)
  {
    poz::UniqueShapes shapes = std::make_unique< poz::UniqueShape[] >(2);
    BOOST_CHECK_THROW(poz::CompositeShape(std::move(shapes), 2), std::invalid_argument);
    BOOST_CHECK_THROW(poz::CompositeShape(std::move(shapes), 2), std::invalid_argument);
  }

BOOST_AUTO_TEST_SUITE_END()
