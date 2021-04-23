#include "test-functions.hpp"
#include "circle.hpp"
#include "rectangle.hpp"

namespace poz = pozdnyakov;

BOOST_AUTO_TEST_CASE(scale_arg_exception_test)
{
  poz::UniqueShape rect = makeRect(99.3, 7, poz::point_t{13, 12});
  poz::UniqueShape circle = makeCircle(88, poz::point_t{77, 13});
  poz::UniqueShape cshape = makeCompositeShape();
  BOOST_CHECK_THROW(circle->safeScale(-2), std::invalid_argument);
  BOOST_CHECK_THROW(rect->safeScale(-2), std::invalid_argument);
  BOOST_CHECK_THROW(cshape->safeScale(0), std::invalid_argument);
}
