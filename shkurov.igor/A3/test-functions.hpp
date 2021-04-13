#ifndef TEST_FUNCTIONS_HPP
#define TEST_FUNCTIONS_HPP

#include <memory>
#include <stdexcept>
#include <limits>

#include "shape.hpp"
#include "rectangle.hpp"
#include "circle.hpp"
#include "composite-shape.hpp"

const double TOLERANCE = std::numeric_limits< double >::epsilon();

namespace shkurov
{
  std::unique_ptr< shkurov::Shape > makeBadCircle();
  std::unique_ptr< shkurov::Shape > makeBadRectangle();
  std::unique_ptr< shkurov::Shape > makeCircle();
  std::unique_ptr< shkurov::Shape > makeRectangle();
  std::unique_ptr< shkurov::Shape > makeCompositeShape();

  void testMoveToPoint(shkurov::Shape& shape);
  void testScale(shkurov::Shape& shape);
  void invalidScale(shkurov::Shape& shape);
}

#endif
