#include "test-functions.hpp"
#include "circle.hpp"
#include "rectangle.hpp"
#include "exceptions.hpp"

BOOST_AUTO_TEST_CASE(scale_arg_exception_test)
{
  UniqueShape rect = makeRect();
  UniqueShape circle = makeCircle();
  UniqueShape cshape = makeCompositeShape();
  BOOST_CHECK_THROW(circle->scale(-2), ScaleException);
  BOOST_CHECK_THROW(rect->scale(-2), ScaleException);
  BOOST_CHECK_THROW(cshape->scale(0), ScaleException);
}
