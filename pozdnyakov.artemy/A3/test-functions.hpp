#ifndef TEST_FUNCTION_HPP
#define TEST_FUNCTION_HPP

#include <boost/test/unit_test.hpp>
#include "composite_shape.hpp"

namespace pozdnyakov
{
  const double delta = 0.5;
  pozdnyakov::UniqueShape makeRect();
  pozdnyakov::UniqueShape makeCircle();
  pozdnyakov::UniqueShape makeCompositeShape();
}

#endif
