#ifndef TEST_FUNCTIONS_HPP
#define TEST_FUNCTIONS_HPP

#include <limits>

#include "shape.hpp"
#include "rectangle.hpp"
#include "circle.hpp"
#include "composite-shape.hpp"

const double EPSILON = std::numeric_limits< double >::epsilon();

namespace shkurov
{
  std::unique_ptr< Shape > makeBadCircle();
  std::unique_ptr< Shape > makeBadRectangle();
  std::unique_ptr< Shape > makeCircle();
  std::unique_ptr< Shape > makeRectangle();
  std::unique_ptr< Shape > makeCompositeShape();

  void testMoveToPoint(Shape& shape);
  void testScale(Shape& shape);
  void invalidScale(Shape& shape);
}

#endif
