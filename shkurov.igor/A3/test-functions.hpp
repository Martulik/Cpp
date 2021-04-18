#ifndef TEST_FUNCTIONS_HPP
#define TEST_FUNCTIONS_HPP

#include <limits>

#include "shape.hpp"
#include "rectangle.hpp"
#include "circle.hpp"
#include "composite-shape.hpp"

using shapePtr = unique_ptr< shkurov::Shape >;

using std::unique_ptr;

const double EPSILON = std::numeric_limits< double >::epsilon();

namespace shkurov
{
  shapePtr makeBadCircle();
  shapePtr makeBadRectangle();
  shapePtr makeCircle();
  shapePtr makeRectangle();
  shapePtr makeCompositeShape();

  void testMoveToPoint(Shape& shape);
  void testScale(Shape& shape);
  void invalidScale(Shape& shape);
}

#endif
