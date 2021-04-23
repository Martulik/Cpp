#include "test-functions.hpp"
#include "circle.hpp"
#include "rectangle.hpp"

namespace poz = pozdnyakov;

BOOST_AUTO_TEST_CASE(scale_arg_exception_test)
{
  poz::UniqueShape rect = makeRect();
  poz::UniqueShape circle = makeCircle();
  poz::UniqueShape cshape = makeCompositeShape();
  BOOST_CHECK_THROW(circle->scale(-2), std::invalid_argument);
  BOOST_CHECK_THROW(rect->scale(-2), std::invalid_argument);
  BOOST_CHECK_THROW(cshape->scale(0), std::invalid_argument);
}
