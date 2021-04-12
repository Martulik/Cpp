#ifndef TEST_FUNCTIONS_HPP
#define TEST_FUNCTIONS_HPP

#include "shape.hpp"
#include <memory>

#include "rectangle.hpp"
#include "circle.hpp"
#include "composite-shape.hpp"

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

  namespace test_utility
  {
    double getX(const shkurov::Shape& shape);
    double getY(const shkurov::Shape& shape);
    double getHeight(const shkurov::Shape& shape);
    double getWidth(const shkurov::Shape& shape);
  }
}

#endif
