#include "test-functions.hpp"
#include "circle.hpp"
#include "exceptions.hpp"

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
    UniqueShapes shapes = std::make_unique< UniqueShape[] >(2);
    BOOST_CHECK_THROW(poz::CompositeShape(std::move(shapes), 2), ShapeArgException);
    BOOST_CHECK_THROW(poz::CompositeShape(std::move(shapes), 2), ShapeArgException);
  }

BOOST_AUTO_TEST_SUITE_END()
